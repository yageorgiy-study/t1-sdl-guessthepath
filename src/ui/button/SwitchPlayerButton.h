//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_SWITCHPLAYERBUTTON_H
#define GUESSTHEPATH_SWITCHPLAYERBUTTON_H


#include "../Button.h"

class SwitchPlayerButton : public Button {
public:
    SwitchPlayerButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_SWITCHPLAYERBUTTON_H
