#include <random>
#include <iostream>
#include <ctime>
#include "Map.h"
#include "cell/Bomb.h"
#include "cell/EmptyPath.h"
#include "cell/Finish.h"
#include "../../Utils.h"
#include "../../ui/screen/GameScreen.h"

Map::Map(Game * game, int player_x, int player_y) : Renderable(game) {
    this->player_x = player_x;
    this->player_y = player_y;
    this->game = game;

    this->cells = (new Cell**[this->height]);
    for(int i = 0; i < this->height; i++)
    {
        this->cells[i] = new Cell*[this->width];
        for(int j = 0; j < this->width; j++)
        {
            this->cells[i][j] = nullptr;
        }
    }
}

Map::~Map() {
    for(int i = 0; i < this->height; i++)
        delete this->cells[i];
    delete []this->cells;
}

void Map::generateMap() {
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
        {
            if(this->cells[i][j])
                delete this->cells[i][j];

            this->cells[i][j] = new EmptyPath(this->game);
//            this->cells[i][j]->setVisited(true);
        }

    // generate bombs
    for(int i = 0; i < 10; i++)
    {
        auto h = Utils::generateRandomInt(0, this->height - 1);
        auto w = Utils::generateRandomInt(0, this->width - 1);

        this->cells[h][w] = new Bomb(this->game);
//        this->cells[h][w]->setVisited(true);
    }

    // player cell
    this->cells[this->player_y][this->player_x]->setVisited(true);

    // finish cell
    this->cells[this->height - 1][this->width - 1] = new Finish(this->game);
    this->cells[this->height - 1][this->width - 1]->setVisited(true);
}



void Map::render(int start_x, int start_y) {
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
        {
            auto cell = this->cells[i][j];
            if(cell == nullptr) continue;

            cell->w = (int)round((double)this->w / this->height);
            cell->h = (int)round((double)this->h / this->width);
            cell->render(start_x + this->x + cell->w * (i), start_y + this->y + cell->h * (j), this->showAll);

            if(i == player_y && j == player_x)
            {
                Asset* texture;

                if(!dead)
                    texture = game->assetManager->assets[Asset::Textures::PLAYER];
                else
                    texture = game->assetManager->assets[Asset::Textures::SKULL];

                texture->renderRect->w = cell->w;
                texture->renderRect->h = cell->h;
                texture->renderRect->x = start_x + this->x + cell->w * (i);
                texture->renderRect->y = start_y + this->y + cell->h * (j);

                texture->render();
            }
        }
}

void Map::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void Map::keyUp(SDL_KeyboardEvent &e) {
//    this->tapped = false;
}

void Map::keyDown(SDL_KeyboardEvent &e) {
//    if(this->tapped) return;
//    this->tapped = true;

    if(dead || win) return;

    switch(e.keysym.scancode)
    {
        case SDL_SCANCODE_W:
            if(this->player_x - 1 >= 0)
                this->player_x--;
            break;

        case SDL_SCANCODE_A:
            if(this->player_y - 1 >= 0)
                this->player_y--;
            break;

        case SDL_SCANCODE_S:
            if(this->player_x + 1 < this->width)
                this->player_x++;
            break;

        case SDL_SCANCODE_D:
            if(this->player_y + 1 < this->height)
                this->player_y++;
            break;
    }

    // Game logic
    auto cur = this->cells[this->player_y][this->player_x];
    cur->setVisited(true);

    // Is Bomb class
    if(dynamic_cast<Bomb*>(cur) != nullptr)
    {
        dead = true;
        return;
    }

    // Is Finish class
    if(dynamic_cast<Finish*>(cur) != nullptr)
    {
        // todo: rebase?
        if(((GameScreen *)(game->currentScreen)) != nullptr)
            ((GameScreen *)(game->currentScreen))->win();

        win = true;
        return;
    }
}
