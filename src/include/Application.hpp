#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include "Window.hpp"
#include "WorldController.hpp"
#include "player/Player.hpp"
#include "UI.hpp"

#include <SDL2/SDL_ttf.h>

class Application
{
private:
    Window* game_window;
    SDL_Event event;
    WorldController* world;
    Player* player;

    void initialize();

    void main_loop();
    void update();
    void draw();
    void destroy();
public:
    void run();
};

#endif