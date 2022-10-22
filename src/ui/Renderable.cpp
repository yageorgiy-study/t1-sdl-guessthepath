#include <iostream>
#include "Renderable.h"

Renderable::Renderable(Game *game) : game(game) {}

void Renderable::callLeftMouseClicked(SDL_MouseButtonEvent &b) {
    if(visible)
        leftMouseClicked(b);
}

void Renderable::callRender(int start_x, int start_y) {
    if(visible)
        render(start_x, start_y);
}
