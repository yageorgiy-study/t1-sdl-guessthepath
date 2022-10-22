//
// Created by Gosha on 14.06.2022.
//

#include "HelpScreen.h"
#include "../text/TitleText.h"
#include "../../Game.h"
#include "../button/BackButton.h"
#include "MenuScreen.h"

HelpScreen::HelpScreen(Game *game) : Screen(game) {
    this->add(new BackButton(game, new MenuScreen(game)));
}

void HelpScreen::renderBackground(int start_x, int start_y) {
    auto assetsManager = game->assetManager;
    auto window_width = game->window_width;
    auto window_height = game->window_height;

    auto texture = assetsManager->assets[Asset::Textures::HELP_INSTRUCTIONS];

    auto pos = texture->getRect();
    texture->renderRect->w = std::min(pos.w, window_width);
    texture->renderRect->h = std::min(pos.h, window_height);
    texture->renderRect->x = window_width / 2 - texture->renderRect->w / 2;
    texture->renderRect->y = window_height / 2 - texture->renderRect->h / 2;

    texture->render();

    auto backButton = this->elements[0];
    backButton->x = 10;
    backButton->y = 10;
    backButton->w = 300 / 3;
    backButton->h = 100 / 3;
}

void HelpScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void HelpScreen::keyUp(SDL_KeyboardEvent &e) {

}

void HelpScreen::keyDown(SDL_KeyboardEvent &e) {

}
