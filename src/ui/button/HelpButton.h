//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_HELPBUTTON_H
#define GUESSTHEPATH_HELPBUTTON_H


#include "../Button.h"

class HelpButton : public Button {
public:
    HelpButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_HELPBUTTON_H
