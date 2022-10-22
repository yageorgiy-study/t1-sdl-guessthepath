#include <iostream>
#include <SDL_rect.h>
#include <SDL_timer.h>
#include "WelcomeScreen.h"

#include "../../Game.h"
#include "MenuScreen.h"
#include "SwitchPlayerScreen.h"

void WelcomeScreen::renderBackground(int start_x, int start_y) {
    auto assetsManager = game->assetManager;
    auto window_width = game->window_width;
    auto window_height = game->window_height;

    auto texture = assetsManager->assets[Asset::Textures::STARTUP];

    auto pos = texture->getRect();
    texture->renderRect->w = std::min(pos.w, window_width);
    texture->renderRect->h = std::min(pos.h, window_height);
    texture->renderRect->x = window_width / 2 - texture->renderRect->w / 2;
    texture->renderRect->y = window_height / 2 - texture->renderRect->h / 2;

    texture->render();

    if(SDL_GetTicks() > this->waitMs)
        gotoNext();
}

WelcomeScreen::WelcomeScreen(Game *game) : Screen(game) {}

void WelcomeScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {
    gotoNext();
}

void WelcomeScreen::keyUp(SDL_KeyboardEvent &e) {

}

void WelcomeScreen::keyDown(SDL_KeyboardEvent &e) {

}

void WelcomeScreen::gotoNext() {
    if(this->game->records->username.empty())
        this->game->switchScreen(new SwitchPlayerScreen(this->game));
    else
        this->game->switchScreen(new MenuScreen(this->game));
}
