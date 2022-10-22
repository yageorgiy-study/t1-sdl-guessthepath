//
// Created by Gosha on 14.06.2022.
//

#include "ExitButton.h"
#include "../../Game.h"

ExitButton::ExitButton(Game *game) : Button(game, "Выйти") {}

void ExitButton::pressed() {
    this->game->forceQuit = true;
}
