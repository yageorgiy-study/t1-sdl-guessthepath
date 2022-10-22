#ifndef GUESSTHEPATH_TEXTFIELD_H
#define GUESSTHEPATH_TEXTFIELD_H


#include "Renderable.h"
#include "Text.h"

class TextField : public Renderable {
protected:
    bool active = false;
    Text * text = nullptr;
    std::string value = "";
    bool caps = false;
public:
    TextField(Game *game);

    virtual ~TextField();

    int charsVisible = 26;
    int maxChars = 255;

    void render(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void setActive(bool active);

    bool isActive() const;
    bool isHovered();

    const std::string &getValue() const;

    void setValue(const std::string &value);

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_TEXTFIELD_H
