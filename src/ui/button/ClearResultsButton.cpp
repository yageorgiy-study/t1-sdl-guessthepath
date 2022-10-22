//
// Created by Gosha on 18.06.2022.
//

#include "ClearResultsButton.h"
#include "../../Game.h"
#include "../screen/RecordsScreen.h"

ClearResultsButton::ClearResultsButton(Game *game) : Button(game, "Очистить список") {}

void ClearResultsButton::pressed() {
    this->game->records->clear();
    this->game->switchScreen(new RecordsScreen(game));
}
