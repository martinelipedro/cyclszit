#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include "Window.hpp"
#include "WorldController.hpp"
#include "Player.hpp"
#include "UI.hpp"

#include <SDL2/SDL_ttf.h>

class Application
{
private:
    Window* game_window;
    SDL_Event event;
    WorldController* world;
    Player* player;
    UIFStatusBar* status_bar;
    UIManager* ui_manager;

    void initialize();
    void initialize_window();

    void main_loop();
    void update();
    void draw();
public:
    void run();
};

#endif