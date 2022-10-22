#ifndef GUESSTHEPATH_PLAYBUTTON_H
#define GUESSTHEPATH_PLAYBUTTON_H


#include "../Button.h"

class PlayButton : public Button {
public:
    PlayButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_PLAYBUTTON_H
