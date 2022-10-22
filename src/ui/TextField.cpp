#include <iostream>
#include "TextField.h"
#include "../Game.h"
#include "Defaults.h"

TextField::TextField(Game *game) : Renderable(game) {
    this->text = new Text(game, "", TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::TEXT_FIELD_FONT_SIZE), Defaults::TEXTFIELD_FONT_COLOR());
}

void TextField::render(int start_x, int start_y) {
    if(this->game == nullptr || this->game->renderer == nullptr) return;

    int valLen = this->value.length();

    SDL_Rect squareRect;
    squareRect.w = this->w;
    squareRect.h = this->h;
    squareRect.x = start_x + this->x;
    squareRect.y = start_y + this->y;

    auto textFieldColor = Defaults::TEXTFIELD_COLOR();

    SDL_SetRenderDrawColor(this->game->renderer, textFieldColor.r, textFieldColor.g, textFieldColor.b, textFieldColor.a);
    SDL_RenderFillRect(this->game->renderer, &squareRect);

    // hide extra chars
    if(valLen > this->charsVisible)
    {
        this->text->setText("..." + this->value.substr (valLen - this->charsVisible, this->charsVisible));
    }

    this->text->x = squareRect.x + this->w / 2 - this->text->w / 2;
    this->text->y = squareRect.y + this->h / 2 - this->text->h / 2;
    this->text->render(start_x, start_y);

    // линия редактирования
    if(isActive())
    {
        const int time = 500;
        if((SDL_GetTicks() % (time * 2)) < time) return;

        auto textFieldFontColor = Defaults::TEXTFIELD_FONT_COLOR();
        const int cursorSize = 20;

        squareRect.w = 2;
        squareRect.h = cursorSize;
        squareRect.x = this->text->x + this->text->w + 3;
        squareRect.y = start_y + this->y + this->h / 2 - cursorSize / 2;

        // max char animation
        if(valLen >= maxChars){
            SDL_SetRenderDrawColor(
                    this->game->renderer,
                    255,
                    0,
                    0,
                    textFieldFontColor.a
            );
        } else {
            SDL_SetRenderDrawColor(
                    this->game->renderer,
                    textFieldFontColor.r,
                    textFieldFontColor.g,
                    textFieldFontColor.b,
                    textFieldFontColor.a
            );
        }


        SDL_RenderFillRect(this->game->renderer, &squareRect);
    }
}

void TextField::leftMouseClicked(SDL_MouseButtonEvent &b) {
    this->active = isHovered();
}

bool TextField::isActive() const {
    return active;
}

bool TextField::isHovered() {
    int actual_x = game->mouse_x - game->window_x;
    int actual_y = game->mouse_y - game->window_y;
    return (actual_x >= this->x && actual_x <= this->x + this->w &&
            actual_y >= this->y && actual_y <= this->y + this->h);
}

TextField::~TextField() {
    delete this->text;
}

const std::string &TextField::getValue() const {
    return value;
}

void TextField::setValue(const std::string &value) {
    TextField::value = value;
    this->text->setText(value);
}

void TextField::keyUp(SDL_KeyboardEvent &e) {

}

void TextField::keyDown(SDL_KeyboardEvent &e) {
    if(!isActive()) return;



    // ignore shift
    if(e.keysym.scancode == SDL_SCANCODE_RSHIFT || e.keysym.scancode == SDL_SCANCODE_LSHIFT)
        return;

    // caps switch
    if(e.keysym.scancode == SDL_SCANCODE_CAPSLOCK){
        caps = !caps;
        return;
    }

    // delete last char
    if(e.keysym.scancode == SDL_SCANCODE_BACKSPACE){
        if(this->value.length() > 0) {
            this->value.pop_back();
            this->setValue(this->value);
        }
        return;
    }

    // char limit
    if(this->value.length() + 1 > this->maxChars)
        return;

    // to upper
    char key = (char)e.keysym.sym;
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if(state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT] || caps){
        key = toupper(key);
    }

    this->setValue(this->getValue() + key);
}

void TextField::setActive(bool active) {
    TextField::active = active;
}

