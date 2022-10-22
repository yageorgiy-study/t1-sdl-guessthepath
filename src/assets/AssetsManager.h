//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_ASSETSMANAGER_H
#define GUESSTHEPATH_ASSETSMANAGER_H


#include <string>
#include <map>
#include "Asset.h"

class AssetsManager {
    SDL_Renderer * renderer = nullptr;
public:
    AssetsManager(SDL_Renderer *renderer);

    virtual ~AssetsManager();

    std::map<Asset::Textures, Asset*> assets;
    void addAssetFromBMP(Asset::Textures id, std::string filename);
};


#endif //GUESSTHEPATH_ASSETSMANAGER_H
