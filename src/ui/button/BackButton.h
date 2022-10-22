#ifndef GUESSTHEPATH_BACKBUTTON_H
#define GUESSTHEPATH_BACKBUTTON_H


#include "../Button.h"
#include "../screen/Screen.h"

class BackButton : public Button {
protected:
    Screen * screen;
public:
    BackButton(Game *game, Screen * screen);

    void pressed() override;
};


#endif //GUESSTHEPATH_BACKBUTTON_H
