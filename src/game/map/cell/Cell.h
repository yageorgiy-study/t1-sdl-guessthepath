//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_CELL_H
#define GUESSTHEPATH_CELL_H


#include "../../../Game.h"

class Cell {
protected:
    Game * game = nullptr;

    bool visited = false;

public:
//    short type = -1;
//    static const short UNDEFINED = -1;
    int w = 16, h = 16;

//    bool isVisited() const;

    void setVisited(bool visited);

    Cell(Game * game);
    virtual void render(int x, int y, bool forceShown) = 0;
    void callRender(int x, int y, bool forceShown);
};


#endif //GUESSTHEPATH_CELL_H
