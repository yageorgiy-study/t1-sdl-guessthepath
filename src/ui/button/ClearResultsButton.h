//
// Created by Gosha on 18.06.2022.
//

#ifndef GUESSTHEPATH_CLEARRESULTSBUTTON_H
#define GUESSTHEPATH_CLEARRESULTSBUTTON_H


#include "../Button.h"

class ClearResultsButton : public Button {
public:
    ClearResultsButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_CLEARRESULTSBUTTON_H
