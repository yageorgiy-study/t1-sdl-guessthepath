//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_MENUSCREEN_H
#define GUESSTHEPATH_MENUSCREEN_H


#include "Screen.h"

class MenuScreen : public Screen {
public:
    MenuScreen(Game *game);

public:
    void renderBackground(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_MENUSCREEN_H
