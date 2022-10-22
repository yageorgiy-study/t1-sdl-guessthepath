//
// Created by Gosha on 15.06.2022.
//

#include "ApplyUsernameButton.h"
#include "../TextField.h"
#include "../../Game.h"
#include "../screen/MenuScreen.h"

ApplyUsernameButton::ApplyUsernameButton(Game *game, TextField * field) : Button(game, "Применить") {
    this->textField = field;
}

void ApplyUsernameButton::pressed() {
    if(this->textField->getValue().compare(""))
    {
        this->game->records->username = this->textField->getValue();
    } else {
        if(this->game->records->username.empty())
            this->game->records->username = "Player";
    }



    this->game->switchScreen(new MenuScreen(game));
}
