#ifndef GUESSTHEPATH_WELCOMESCREEN_H
#define GUESSTHEPATH_WELCOMESCREEN_H

#include "Screen.h"
#include "../../assets/AssetsManager.h"

class WelcomeScreen : public Screen {
protected:
    int waitMs = 3000;

    void gotoNext();

public:
    WelcomeScreen(Game *game);
    void renderBackground(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_WELCOMESCREEN_H
