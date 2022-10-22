#ifndef GUESS_THE_PATH_GAME_H
#define GUESS_THE_PATH_GAME_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include "ui/screen/Screen.h"
#include "assets/AssetsManager.h"
#include "records/Records.h"
#include "window/GameWindow.h"

class Game {

public:
    Game();

protected:
    std::string title = "Guess The Path";

    SDL_Event* event;

    void render();
    void loadTextures();
    void unload();

    void pollEvents();
    void mouseClicked(SDL_MouseButtonEvent& b);

    void keyUp(SDL_KeyboardEvent& e);
    void keyDown(SDL_KeyboardEvent& e);

public:
    SDL_Renderer* renderer = nullptr;
//    SDL_Window* window = nullptr;
    GameWindow* gameWindow = nullptr;
    AssetsManager * assetManager = nullptr;
    Records * records = nullptr;
    Screen* currentScreen = nullptr;

    int window_width, window_height, window_x, window_y = 0;

    int mouse_x, mouse_y = 0;

    bool forceQuit = false;

    void init(int argc, char* argv[]);
    void switchScreen(Screen* newScreen);

    void startup();
};


#endif //GUESS_THE_PATH_GAME_H
