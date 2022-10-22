//
// Created by Gosha on 15.06.2022.
//

#include "Finish.h"

Finish::Finish(Game *game) : Cell(game) {}

void Finish::render(int x, int y, bool forceShown) {
    Asset * asset = nullptr;

    if(this->visited || forceShown){
        asset = this->game->assetManager->assets[Asset::FINISH];
    } else {
        asset = this->game->assetManager->assets[Asset::UNKNOWN_PATH];
    }

    asset->renderRect->x = x;
    asset->renderRect->y = y;
    asset->renderRect->w = this->w;
    asset->renderRect->h = this->h;
    asset->render();
}
