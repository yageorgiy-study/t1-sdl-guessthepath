//
// Created by Gosha on 14.06.2022.
//

#include "RecordsButton.h"
#include "../../Game.h"
#include "../screen/RecordsScreen.h"

RecordsButton::RecordsButton(Game *game) : Button(game, "Рекорды") {}

void RecordsButton::pressed() {
    this->game->switchScreen(new RecordsScreen(game));
}
