//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_MAP_H
#define GUESSTHEPATH_MAP_H
#include "./cell/Cell.h"

class Map : public Renderable {
    int width = 16;
    int height = 16;

    int player_x = 0, player_y = 0;

//    bool tapped = false;
    Cell* ** cells = nullptr;

    Game * game;

public:
    bool dead = false;
    bool showAll = false;
    bool win = false;
    Map(Game * game, int player_x, int player_y);
    virtual ~Map();
    void generateMap();

    void render(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    void keyUp(SDL_KeyboardEvent &e) override;

    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_MAP_H
