//
// Created by Gosha on 14.06.2022.
//

#include "BackButton.h"
#include "../../Game.h"

BackButton::BackButton(Game *game, Screen * screen) : Button(game, "<< Назад"), screen(screen) {}

void BackButton::pressed() {
    this->game->switchScreen(this->screen);
}
