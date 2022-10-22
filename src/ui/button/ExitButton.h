#ifndef GUESSTHEPATH_EXITBUTTON_H
#define GUESSTHEPATH_EXITBUTTON_H


#include "../Button.h"

class ExitButton : public Button {
public:
    ExitButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_EXITBUTTON_H
