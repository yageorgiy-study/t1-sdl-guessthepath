#include <string>
#include <SDL_render.h>
#include <iostream>
#include "DefaultWindow.h"

DefaultWindow::DefaultWindow(std::string title, int width, int height, bool resizeable) {

    Uint32 flags = SDL_WINDOW_SHOWN;
    if(resizeable) flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

    this->sdlWindow = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            flags
    );

    if(this->sdlWindow){
        SDL_SetWindowMinimumSize(this->sdlWindow, width, height);
    }
}

SDL_Renderer * DefaultWindow::createRenderer() {
    return SDL_CreateRenderer(this->sdlWindow, -1, SDL_RENDERER_ACCELERATED);
}

void DefaultWindow::requireDimensions(int *x, int *y, int *w, int *h) const {
    if(sdlWindow) {
        SDL_GetWindowSize(sdlWindow, w, h);
        SDL_GetWindowPosition(sdlWindow, x, y);
    } else {
        *x = 0;
        *y = 0;
        *h = 0;
        *w = 0;
    }
}

DefaultWindow::~DefaultWindow() {
    if(this->sdlWindow)
        SDL_DestroyWindow(this->sdlWindow);
}
