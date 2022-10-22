//
// Created by Gosha on 13.06.2022.
//

#include "Button.h"
#include "Defaults.h"
#include <SDL_ttf.h>
#include <iostream>
#include "../Game.h"

Button::Button(Game *game, std::string textString) : Renderable(game) {
    this->updateText(std::move(textString));
}

Text *Button::getText() const {
    return text;
}

void Button::setText(std::string text) {
    this->updateText(std::move(text));
}

Button::~Button() {
    delete text;
}

void Button::updateText(std::string textString){
    this->text = new Text(game, std::move(textString), TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::BUTTON_FONT_SIZE), Defaults::BUTTON_TEXT_COLOR());
}

void Button::render(int start_x, int start_y) {
    if(this->game == nullptr || this->game->renderer == nullptr) return;

    SDL_Rect squareRect;
    squareRect.w = this->w;
    squareRect.h = this->h;
    squareRect.x = start_x + this->x;
    squareRect.y = start_y + this->y;

    auto buttonColor = Defaults::BUTTON_COLOR();

    if(isHovered())
        buttonColor = Defaults::ACTIVE_BUTTON_COLOR();

    SDL_SetRenderDrawColor(this->game->renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(this->game->renderer, &squareRect);

    this->text->x = squareRect.x + this->w / 2 - this->text->w / 2;
    this->text->y = squareRect.y + this->h / 2 - this->text->h / 2;
    this->text->render(start_x, start_y);
}

void Button::leftMouseClicked(SDL_MouseButtonEvent &b) {
    if(isHovered())
        this->pressed();
}

bool Button::isHovered() {
    int actual_x = game->mouse_x - game->window_x;
    int actual_y = game->mouse_y - game->window_y;
    return (actual_x >= this->x && actual_x <= this->x + this->w &&
       actual_y >= this->y && actual_y <= this->y + this->h);
}

void Button::keyUp(SDL_KeyboardEvent &e) {

}

void Button::keyDown(SDL_KeyboardEvent &e) {

}
