//
// Created by Gosha on 18.06.2022.
//

#ifndef GUESSTHEPATH_PRINTBUTTON_H
#define GUESSTHEPATH_PRINTBUTTON_H


#include "../Button.h"

class PrintButton : public Button {
public:
    PrintButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_PRINTBUTTON_H
