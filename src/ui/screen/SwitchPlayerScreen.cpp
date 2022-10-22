#include "SwitchPlayerScreen.h"
#include "../TextField.h"
#include "../text/InfoText.h"
#include "../../Game.h"
#include "../button/BackButton.h"
#include "MenuScreen.h"
#include "../button/ApplyUsernameButton.h"

SwitchPlayerScreen::SwitchPlayerScreen(Game *game) : Screen(game) {
    this->add(new InfoText(game, "Введите имя пользователя:"));

    auto textField = new TextField(game);
    textField->setActive(true);
    textField->setValue(game->records->username);
    this->add(textField);

    this->add(new ApplyUsernameButton(game, textField));
}

void SwitchPlayerScreen::renderBackground(int start_x, int start_y) {
    auto* titleText = this->elements[0];
    titleText->x = game->window_width / 2 - titleText->w / 2;
    titleText->y = 100;

    auto* textField = this->elements[1];
    textField->w = 300;
    textField->h = 100 / 2;
    textField->x = game->window_width / 2 - textField->w / 2;
    textField->y = 300;

    auto* backButton = this->elements[2];
    backButton->w = 300;
    backButton->h = 100 / 2;
    backButton->x = game->window_width / 2 - backButton->w / 2;
    backButton->y = 360;
}

void SwitchPlayerScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void SwitchPlayerScreen::keyUp(SDL_KeyboardEvent &e) {

}

void SwitchPlayerScreen::keyDown(SDL_KeyboardEvent &e) {

}
