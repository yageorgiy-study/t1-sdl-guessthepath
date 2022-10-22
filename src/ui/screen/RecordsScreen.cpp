//
// Created by Gosha on 14.06.2022.
//

#include "RecordsScreen.h"
#include "../Defaults.h"
#include "../../Game.h"
#include "../button/BackButton.h"
#include "MenuScreen.h"
#include "../text/TitleText.h"
#include "../text/InfoText.h"
#include "../button/ClearResultsButton.h"
#include "../button/PrintButton.h"

RecordsScreen::RecordsScreen(Game *game) : Screen(game) {
    this->add(new BackButton(game, new MenuScreen(game)));
    this->add(new ClearResultsButton(game));
    this->add(new PrintButton(game));

    this->add(new TitleText(game, "..."));

    int i = 1;
    for(const auto& record : game->records->getValues())
    {
        this->add(
            new InfoText(game,
            "#" + std::to_string(i) + ": " + record->player + " за " + std::to_string(record->score / 1000.) + " сек"
            )
        );
        i++;
    }


}

void RecordsScreen::renderBackground(int start_x, int start_y) {
    auto assetsManager = game->assetManager;
    auto window_width = game->window_width;
    auto window_height = game->window_height;

    // Title text
    auto titleText = this->elements[3];
    titleText->x = window_width / 2 - titleText->w / 2;
    titleText->y = 40;

    // Instances
    auto values = this->game->records->getValues();
    auto size = values.size();

    if(size > 0) {
        ((TitleText*)titleText)->setText("Таблица рекордов");

        // BG color
        SDL_Rect boxBgRect;
        const int offset = 250;
        boxBgRect.w = window_width - offset;
        boxBgRect.h = window_height - offset;
        boxBgRect.x = start_x + window_width / 2 - boxBgRect.w / 2;
        boxBgRect.y = start_y + window_height / 2 - boxBgRect.h / 2;

        auto color = Defaults::STATS_COLOR();
        SDL_SetRenderDrawColor(this->game->renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(this->game->renderer, &boxBgRect);

        const int instancesOffset = 10;
        for (int i = 0; i < size; i++) {
            auto cur = this->elements[i + 4];
            cur->x = instancesOffset + window_width / 2 - boxBgRect.w / 2;
            cur->y = instancesOffset + window_height / 2 - boxBgRect.h / 2 + i * 20;
        }

    } else {
        ((TitleText*)titleText)->setText("Нет результатов");
    }

    // Back button
    auto backButton = this->elements[0];
    backButton->x = 10;
    backButton->y = 10;
    backButton->w = 300 / 3;
    backButton->h = 100 / 3;

    // Clear results button
    auto clearResults = this->elements[1];
    clearResults->x = 120;
    clearResults->y = 10;
    clearResults->w = 150;
    clearResults->h = 100 / 3;

    // Print to file button
    auto printToFile = this->elements[2];
    printToFile->x = 280;
    printToFile->y = 10;
    printToFile->w = 260;
    printToFile->h = 100 / 3;
}

void RecordsScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void RecordsScreen::keyUp(SDL_KeyboardEvent &e) {

}

void RecordsScreen::keyDown(SDL_KeyboardEvent &e) {

}
