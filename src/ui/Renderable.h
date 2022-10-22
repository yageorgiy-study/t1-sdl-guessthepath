#ifndef GUESSTHEPATH_RENDERABLE_H
#define GUESSTHEPATH_RENDERABLE_H


#include <SDL_render.h>
#include <SDL_events.h>

class Game;

class Renderable {
public:
    Renderable(Game *game);
    int x = 0,y = 0,w = 0,h = 0;
    bool visible = true;

    void callRender(int start_x, int start_y);
    void callLeftMouseClicked(SDL_MouseButtonEvent& b);

    virtual void render(int start_x, int start_y) = 0;
    virtual void leftMouseClicked(SDL_MouseButtonEvent& b) = 0;

    virtual void keyUp(SDL_KeyboardEvent &e) = 0;
    virtual void keyDown(SDL_KeyboardEvent &e) = 0;

protected:
    Game * game = nullptr;
};


#endif //GUESSTHEPATH_RENDERABLE_H
