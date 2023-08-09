#include "include/Application.hpp"
#include "include/constants.hpp"

#define SDL_INITIALIZATION_FLAGS SDL_INIT_VIDEO

void Application::run()
{
    this->initialize();
    this->main_loop();
}

void Application::initialize()
{
    SDL_Init(SDL_INITIALIZATION_FLAGS);
    this->initialize_window();
    this->world = new World;
    this->world->populate_matrix();
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

void Application::update()
{
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    while (SDL_PollEvent(&this->event) > 0)
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
                world->check_mouse_click({mouse_x, mouse_y});
            }
        }
    }
}

#include <iostream>

// xs = offsetx + ((x * tile_width / 2) - (y * tile_width / 2))
// ys = offsety + ((y * tile_height / 2) - (x * tile_height / 2))

void Application::draw()
{
    this->world->draw(this->game_window->get_window_surface());

    SDL_UpdateWindowSurface(this->game_window->get_object());
}