#include <iostream>
#include <algorithm>

#include "Game.h"

int main(int argc, char* argv[])
{
    Game* app = new Game();
    app->init(argc, argv);
    return 0;
}