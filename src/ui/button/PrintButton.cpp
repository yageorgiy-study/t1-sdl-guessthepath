//
// Created by Gosha on 18.06.2022.
//

#include "PrintButton.h"
#include "../../Game.h"
#include "../screen/MenuScreen.h"

PrintButton::PrintButton(Game *game) : Button(game, "Подготовить файл для печати") {}

void PrintButton::pressed() {
    game->records->printToFile();
    game->switchScreen(new MenuScreen(game));
}
