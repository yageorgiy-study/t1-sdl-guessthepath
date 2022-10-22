//
// Created by Gosha on 14.06.2022.
//

#include "SwitchPlayerButton.h"
#include "../../Game.h"
#include "../screen/SwitchPlayerScreen.h"

SwitchPlayerButton::SwitchPlayerButton(Game *game) : Button(game, "Сменить игрока") {}

void SwitchPlayerButton::pressed() {
    this->game->switchScreen(new SwitchPlayerScreen(game));
}
