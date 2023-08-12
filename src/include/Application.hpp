#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include "Window.hpp"
#include "WorldController.hpp"
#include "Player.hpp"
#include "UI.hpp"

class Application
{
private:
    Window* game_window;
    SDL_Event event;
    WorldController* world;
    Player* player;
    UIFStatusBar* status_bar;
    UIManager* ui_manager;

    void draw_bar(int x, int y, int w, int h, SDL_Color bg, SDL_Color fg, float percent);


    void initialize();
    void initialize_window();

    void main_loop();
    void update();
    void draw();
public:
    void run();
};

#endif