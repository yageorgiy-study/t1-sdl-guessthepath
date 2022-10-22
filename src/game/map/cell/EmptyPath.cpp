//
// Created by Gosha on 15.06.2022.
//

#include "EmptyPath.h"

EmptyPath::EmptyPath(Game *game) : Cell(game) {}

void EmptyPath::render(int x, int y, bool forceShown) {
    Asset * asset = nullptr;

    if(this->visited || forceShown){
        asset = this->game->assetManager->assets[Asset::EMPTY_PATH];
    } else {
        asset = this->game->assetManager->assets[Asset::UNKNOWN_PATH];
    }

    asset->renderRect->x = x;
    asset->renderRect->y = y;
    asset->renderRect->w = this->w;
    asset->renderRect->h = this->h;
    asset->render();
}
