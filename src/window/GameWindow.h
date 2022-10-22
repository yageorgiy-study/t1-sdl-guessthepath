//
// Created by Gosha on 18.06.2022.
//

#ifndef GUESSTHEPATH_GAMEWINDOW_H
#define GUESSTHEPATH_GAMEWINDOW_H


#include <string>
#include "DefaultWindow.h"

class GameWindow : public DefaultWindow {
public:
    GameWindow(const std::string &title);

    virtual ~GameWindow();
};


#endif //GUESSTHEPATH_GAMEWINDOW_H
