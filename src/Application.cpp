#include "include/Application.hpp"
#include "include/constants.hpp"

#define SDL_INITIALIZATION_FLAGS SDL_INIT_VIDEO

uint32_t color_from_rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return (uint32_t)((uint8_t(a) << 24) + (uint8_t(r) << 16) + (uint8_t(g) << 8) + uint8_t(b));
}

void Application::run()
{
    this->initialize();
    this->main_loop();
}

void Application::initialize()
{
    SDL_Init(SDL_INITIALIZATION_FLAGS);
    this->initialize_window();
    this->world = new WorldController(this->game_window->get_window_surface());
    this->world->populate_matrix();
    this->player = new Player(100, 100, 100);
    this->player->wood_qt = 0;
}

void Application::initialize_window()
{
    this->game_window = new Window(constants::window_width, constants::window_height, constants::window_title);
}

void Application::main_loop()
{
    while (this->game_window->is_open())
    {
        this->update();
        this->draw();
    }
}

#include <iostream>

void Application::update()
{
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    while (SDL_PollEvent(&this->event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                this->game_window->close();
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                world->check_mouse_click({mouse_x, mouse_y}, this->player);
                break;
            }
            
        }
    }
}

void Application::draw_bar(int x, int y, int w, int h, SDL_Color bg, SDL_Color fg, float percent)
{
    SDL_Rect* background_rect = new SDL_Rect {x, y, w, h};
    
    SDL_FillRect(this->game_window->get_window_surface(), background_rect, color_from_rgb(bg.r, bg.g, bg.b, bg.a));
    SDL_Rect* border_rect = new SDL_Rect {x + 2, y+ 2, w - 4, h-4};
    SDL_FillRect(this->game_window->get_window_surface(), border_rect, 0);
    SDL_Rect* inner_rect = new SDL_Rect {x + 3, static_cast<int>((y + (h - h * percent)) + 3), static_cast<int>(w - 6.f), static_cast<int>(h * percent- 6.f)};
    SDL_FillRect(this->game_window->get_window_surface(), inner_rect, color_from_rgb(fg.r, fg.g, fg.b, fg.a));
}

void Application::draw()
{
    SDL_FillRect(this->game_window->get_window_surface(), NULL, color_from_rgb(83, 93, 94, 255));
    this->world->draw();
    this->draw_bar(30, 30, 40, 150, {255, 255, 255, 255}, {255, 0, 0, 0}, player->current_life / 100);
    this->draw_bar(80, 30, 40, 150, {255, 255, 255, 255}, {92, 83, 5, 255}, player->current_hunger / 100);
    this->draw_bar(130, 30, 40, 150, {255, 255, 255, 255}, {19, 183, 189, 255}, player->current_thirst / 100);
    this->player->draw(this->game_window->get_window_surface());

    SDL_UpdateWindowSurface(this->game_window->get_object());
}