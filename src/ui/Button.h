//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_BUTTON_H
#define GUESSTHEPATH_BUTTON_H


#include <string>
#include "Renderable.h"
#include "Text.h"

class Button : public Renderable {
protected:
    Text * text = nullptr;
public:

    Button(Game *game, std::string textString);
    virtual ~Button();

    void updateText(std::string textString);

    Text *getText() const;
    void setText(std::string text);
    void render(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent& b) override;

    virtual void pressed() = 0;

    bool isHovered();

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_BUTTON_H
