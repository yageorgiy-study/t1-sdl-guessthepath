#include "PlayButton.h"
#include "../../Game.h"
#include "../screen/GameScreen.h"

PlayButton::PlayButton(Game *game) : Button(game, "Играть") {}

void PlayButton::pressed() {
    this->game->switchScreen(new GameScreen(game));
}
