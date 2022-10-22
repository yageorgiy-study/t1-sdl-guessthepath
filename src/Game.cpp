#include <iostream>
#include <algorithm>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Game.h"
#include "ui/screen/WelcomeScreen.h"

void Game::init(int argc, char **argv) {
    // Неиспользуемые переменные (для устранения лишних уведомлений "warning")
    (void) argc;
    (void) argv;

    // Инициализация SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
    {
        std::cout << "SDL or TTF_Init() could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl
                  << "TTF_Error: " << TTF_GetError() << std::endl;
        return;
    }

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Инициализация для сервера окон X11 на ОС на базе Linux
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        std::cout << "SDL can not disable compositor bypass!" << std::endl;
        return;
    }
#endif

    // Создание окна
    this->gameWindow = new GameWindow(this->title);

    if(!gameWindow->sdlWindow) {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    } else {
//        SDL_SetWindowMinimumSize(this->window, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Создание холста (прорисовщика)
        this->renderer = gameWindow->createRenderer();
        if(!this->renderer) {
            std::cout << "Renderer could not be created!" << std::endl
                      << "SDL_Error: " << SDL_GetError() << std::endl;
        } else {
            this->loadTextures();
            this->startup();

            // Фиксированное количество кадров в секунду
            unsigned a, b, delta; // unsigned обязательно! иначе delta считается не правильно (SDL_GetTicks - unsigned)

            // Цикл рендера
            while(!this->forceQuit) {
                // Get events
                this->pollEvents();

                // фиксация FPS
                a = SDL_GetTicks();
                delta = a - b;
                if (delta <= 1000.0 / 60.0) continue;
                b = a;

                // Размер и позиция окна
//                SDL_GetWindowSize(gameWindow->sdlWindow, &this->window_width, &this->window_height);
//                SDL_GetWindowPosition(gameWindow->sdlWindow, &this->window_x, &this->window_y);
                this->gameWindow->requireDimensions(&this->window_x, &this->window_y, &this->window_width, &this->window_height);

                this->render();

                // Обновить экран
                SDL_RenderPresent(this->renderer);
            }

            this->unload();



            // Удалить прорисовщик
            SDL_DestroyRenderer(this->renderer);
        }

        // Удалить окно
        this->gameWindow->~GameWindow();
    }

    // Завершить работу программы
    SDL_Quit();
}

void Game::render() {
    // Установить цвет очистки экрана
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Очистить экран
    SDL_RenderClear(this->renderer);

    this->currentScreen->render(0, 0);
}

Game::Game() {
    this->event = new SDL_Event;
    this->records = new Records("records.gtp_game.dat");
}

void Game::loadTextures() {
    this->assetManager = new AssetsManager(this->renderer);

    // Основные текстуры
    this->assetManager->addAssetFromBMP(Asset::Textures::STARTUP,                   "res/images/startup.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::HELP_INSTRUCTIONS,         "res/images/help.bmp");

    // Игровая карта
    this->assetManager->addAssetFromBMP(Asset::Textures::BOMB,                      "res/images/bomb.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::EMPTY_PATH,                "res/images/empty_path.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::FINISH,                    "res/images/finish.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::PLAYER,                    "res/images/player.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::UNKNOWN_PATH,              "res/images/unknown_path.bmp");
    this->assetManager->addAssetFromBMP(Asset::Textures::SKULL,                     "res/images/skull.bmp");
}

void Game::unload() {
    delete this->assetManager;
    this->records->writeToFile();
    delete this->records;
    delete this->currentScreen;
    delete this->event;
}

void Game::pollEvents() {
    // вытаскиваем события
    SDL_PollEvent(this->event); // или SDL_WaitEvent
    // Если событие выхода
    if(this->event->type == SDL_QUIT)
    {
        this->forceQuit = true;
        return;
    }

    if(this->event->type == SDL_MOUSEMOTION)
    {
        SDL_GetGlobalMouseState(&mouse_x, &mouse_y);
        return;
    }

    if(this->event->type == SDL_MOUSEBUTTONDOWN)
    {
        this->mouseClicked(this->event->button);
        return;
    }

    if(this->event->type == SDL_KEYDOWN)
    {
//        std::cout << this->event->key.keysym.sym;
//        this->keys[this->event->key.keysym.sym] = true; // при ctrl = out of range -1073740940 (0xC0000374)
        this->keyDown(this->event->key);
        return;
    }

    if(this->event->type == SDL_KEYUP)
    {
//        this->keys[this->event->key.keysym.sym] = false;
        this->keyUp(this->event->key);
        return;
    }

}

void Game::startup() {
    auto welcomeScreen = new WelcomeScreen(this);
    this->switchScreen((Screen *)welcomeScreen);
}

void Game::switchScreen(Screen *newScreen) {
    delete this->currentScreen;
    this->currentScreen = newScreen;
}

void Game::mouseClicked(SDL_MouseButtonEvent& b) {
    if(b.button == SDL_BUTTON_LEFT){
        this->currentScreen->callLeftMouseClicked(b);
    }
}

void Game::keyDown(SDL_KeyboardEvent &e) {
    this->currentScreen->callKeyDown(e);
}

void Game::keyUp(SDL_KeyboardEvent &e) {
    this->currentScreen->callKeyUp(e);
}




