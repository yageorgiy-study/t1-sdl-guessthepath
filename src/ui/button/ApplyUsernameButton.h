//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_APPLYUSERNAMEBUTTON_H
#define GUESSTHEPATH_APPLYUSERNAMEBUTTON_H


#include "../Button.h"
#include "../TextField.h"

class ApplyUsernameButton : public Button {
    TextField * textField;
public:
    ApplyUsernameButton(Game *game, TextField * field);

    void pressed() override;
};


#endif //GUESSTHEPATH_APPLYUSERNAMEBUTTON_H
