#ifndef GUESSTHEPATH_TEXT_H
#define GUESSTHEPATH_TEXT_H


#include <string>
#include <SDL_ttf.h>
#include "Renderable.h"

class Text : public Renderable {
private:
    std::string text = "";
    TTF_Font *font = nullptr;
    SDL_Color text_color = {0, 0, 0};

    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;
    void updateSurface();

public:
    Text(Game *renderer, std::string Text, TTF_Font *font, SDL_Color text_color);

    virtual ~Text();

    void setText(const std::string &text);

    const std::string &getText() const;
    const SDL_Color &getTextColor() const;
    TTF_Font *getFont() const;

    void render(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_TEXT_H
