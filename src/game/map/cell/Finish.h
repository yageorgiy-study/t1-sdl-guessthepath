#ifndef GUESSTHEPATH_FINISH_H
#define GUESSTHEPATH_FINISH_H


#include "Cell.h"

class Finish : public Cell {
public:

//    short type = 2;
//    static const short VALUE = 2;

    Finish(Game *game);
    void render(int x, int y, bool forceShown) override;
};


#endif //GUESSTHEPATH_FINISH_H
