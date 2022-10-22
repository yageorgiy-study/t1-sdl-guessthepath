//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_HELPSCREEN_H
#define GUESSTHEPATH_HELPSCREEN_H


#include "Screen.h"

class HelpScreen : public Screen {
public:
    HelpScreen(Game *game);

    void renderBackground(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_HELPSCREEN_H
