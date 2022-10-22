//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_DEFAULTS_H
#define GUESSTHEPATH_DEFAULTS_H


#include <string>
#include <SDL_pixels.h>

class Defaults {
public:
    static std::string DEFAULT_FONT(){
        return "res/fonts/default.ttf";
    }

    static SDL_Color DEFAULT_COLOR(){
        return {0,0,0};
    }

    static SDL_Color BUTTON_COLOR(){
        return {0,96,255};
    }

    static SDL_Color STATS_COLOR(){
        return {255,186,88};
    }

    static SDL_Color TEXTFIELD_COLOR(){
        return {110,110,110};
    }

    static SDL_Color TEXTFIELD_FONT_COLOR(){
        return {255,255,255};
    }

    static SDL_Color ACTIVE_BUTTON_COLOR(){
        return {78,145,255};
    }

    static SDL_Color BUTTON_TEXT_COLOR(){
        return {255,255,255};
    }

    static const int SMALL_FONT_SIZE = 12;
    static const int MEDIUM_FONT_SIZE = 24;
    static const int LARGE_FONT_SIZE = 28;
    static const int EXTRA_LARGE_FONT_SIZE = 32;

    static const int TITLE_FONT_SIZE = 72;
    static const int BUTTON_FONT_SIZE = 18;
    static const int TEXT_FIELD_FONT_SIZE = 18;
};


#endif //GUESSTHEPATH_DEFAULTS_H
