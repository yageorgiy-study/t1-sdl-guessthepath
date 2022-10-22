//
// Created by Gosha on 13.06.2022.
//

#include "AssetsManager.h"

void AssetsManager::addAssetFromBMP(Asset::Textures id, std::string filename) {
    this->assets.insert(
        std::pair<Asset::Textures, Asset*>(id, new Asset(SDL_LoadBMP(filename.c_str()), this->renderer))
    );
}

AssetsManager::AssetsManager(SDL_Renderer *renderer) : renderer(renderer) {}

AssetsManager::~AssetsManager() {
    for(auto it = this->assets.begin(); it != this->assets.end(); ++it)
    {
        delete it->second;
    }

    this->assets.clear();
}
