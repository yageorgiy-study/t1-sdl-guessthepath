#include <iostream>
#include "Asset.h"

Asset::Asset(SDL_Surface *surface, SDL_Renderer *renderer) : surface(surface), renderer(renderer) {
    this->rect = new SDL_Rect;
    this->rect->w = 0;
    this->rect->h = 0;
    this->rect->x = 0;
    this->rect->y = 0;

    this->renderRect = new SDL_Rect;
    this->renderRect->w = 0;
    this->renderRect->h = 0;
    this->renderRect->x = 0;
    this->renderRect->y = 0;

    if(this->surface && this->renderer){
        this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);

        SDL_QueryTexture(this->texture, NULL, NULL, &this->rect->w, &this->rect->h);
        this->renderRect->w = this->rect->w;
        this->renderRect->h = this->rect->h;
    }
}

Asset::~Asset() {
    if(this->texture) {
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }

    if(this->surface) {
        SDL_FreeSurface(this->surface);
        this->surface = nullptr;
    }

    delete this->rect;
}

void Asset::render() {
    if(this->renderer && this->texture)
        SDL_RenderCopy(this->renderer, this->texture, nullptr, this->renderRect);
}

const SDL_Rect &Asset::getRect() const {
    return *rect;
}

