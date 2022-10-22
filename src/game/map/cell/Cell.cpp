#include "Cell.h"

void Cell::callRender(int x, int y, bool forceShown) {
    this->render(x, y, forceShown);
}

Cell::Cell(Game *game) {
    this->game = game;
}


void Cell::setVisited(bool visited) {
    Cell::visited = visited;
}
