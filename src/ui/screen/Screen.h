#ifndef GUESSTHEPATH_SCREEN_H
#define GUESSTHEPATH_SCREEN_H

#include <SDL_render.h>
#include <vector>
#include "../../assets/AssetsManager.h"
#include "../Renderable.h"

class Game;

class Screen {
protected:
    Game * game;
    std::vector<Renderable *> elements;

public:
    Screen(Game *game);

    virtual ~Screen();

    void renderElements(int start_x, int start_y);
    virtual void renderBackground(int start_x, int start_y) = 0;
    void render(int start_x, int start_y);
    void add(Renderable* r);

    void callLeftMouseClicked(SDL_MouseButtonEvent& b);
    virtual void leftMouseClicked(SDL_MouseButtonEvent& b) = 0;

    virtual void keyUp(SDL_KeyboardEvent& e) = 0;
    virtual void keyDown(SDL_KeyboardEvent& e) = 0;

    void callKeyUp(SDL_KeyboardEvent& e);
    void callKeyDown(SDL_KeyboardEvent& e);

//    void callLeftMouseClicked(SDL_MouseButtonEvent& b);
//    virtual void leftMouseClicked(SDL_MouseButtonEvent& b) = 0;

//    void buttonPressed(SDL_MouseButtonEvent& b);
};


#endif //GUESSTHEPATH_SCREEN_H
