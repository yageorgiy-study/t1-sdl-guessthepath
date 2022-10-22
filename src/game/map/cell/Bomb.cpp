#include "Bomb.h"

Bomb::Bomb(Game *game) : Cell(game) {}

void Bomb::render(int x, int y, bool forceShown) {
    Asset * asset = nullptr;

    if(this->visited || forceShown){
        asset = this->game->assetManager->assets[Asset::BOMB];
    } else {
        asset = this->game->assetManager->assets[Asset::UNKNOWN_PATH];
    }

    asset->renderRect->x = x;
    asset->renderRect->y = y;
    asset->renderRect->w = this->w;
    asset->renderRect->h = this->h;
    asset->render();
}
