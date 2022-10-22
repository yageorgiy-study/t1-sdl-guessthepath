//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_RECORDSBUTTON_H
#define GUESSTHEPATH_RECORDSBUTTON_H


#include "../Button.h"

class RecordsButton : public Button {
public:
    RecordsButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_RECORDSBUTTON_H
