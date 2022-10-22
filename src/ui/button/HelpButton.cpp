//
// Created by Gosha on 14.06.2022.
//

#include "HelpButton.h"
#include "../../Game.h"
#include "../screen/HelpScreen.h"

HelpButton::HelpButton(Game *game) : Button(game, "Справка") {}

void HelpButton::pressed() {
    this->game->switchScreen(new HelpScreen(game));
}
