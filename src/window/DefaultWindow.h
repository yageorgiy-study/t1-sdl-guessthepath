#ifndef GUESSTHEPATH_DEFAULTWINDOW_H
#define GUESSTHEPATH_DEFAULTWINDOW_H


#include <SDL.h>

class DefaultWindow {
public:
    DefaultWindow(std::string title, int width, int height, bool resizeable);

    virtual ~DefaultWindow();

    SDL_Renderer * createRenderer();
    void requireDimensions(int *x, int *y, int *w, int *h) const;
    SDL_Window * sdlWindow = nullptr;
};


#endif //GUESSTHEPATH_DEFAULTWINDOW_H
