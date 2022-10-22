#ifndef GUESSTHEPATH_GAMESCREEN_H
#define GUESSTHEPATH_GAMESCREEN_H


#include "Screen.h"
#include "../../game/map/Map.h"

class GameScreen : public Screen {
public:
    GameScreen(Game *game);

    virtual ~GameScreen();

    Map * map;
    int timeStarted = -1;

    int beReadyShakeRadius = 2;

    int msForRemember = 5000;
    bool dead = false;
    bool paused = false;

    int pauseStarted = -1;

    void renderBackground(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent &b) override;
    void keyUp(SDL_KeyboardEvent &e) override;
    void keyDown(SDL_KeyboardEvent &e) override;

    void win();

    int getTimeElapsed();
};


#endif //GUESSTHEPATH_GAMESCREEN_H
