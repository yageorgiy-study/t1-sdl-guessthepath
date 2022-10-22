//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_ASSET_H
#define GUESSTHEPATH_ASSET_H


#include <SDL_surface.h>
#include <SDL_render.h>

class Asset {
public:
    enum Textures {
        STARTUP,
        HELP_INSTRUCTIONS,

        BOMB,
        EMPTY_PATH,
        FINISH,
        UNKNOWN_PATH,
        PLAYER,
        SKULL
    };

    Asset(SDL_Surface *surface, SDL_Renderer* renderer);
    void render();
    virtual ~Asset();

    const SDL_Rect &getRect() const;

    SDL_Rect* renderRect;
private:
    SDL_Rect* rect;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;
};


#endif //GUESSTHEPATH_ASSET_H
