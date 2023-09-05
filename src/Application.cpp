#include "include/Application.hpp"
#include "include/helpers.hpp"
#include "include/defs.hpp"

#define SDL_INITIALIZATION_FLAGS SDL_INIT_VIDEO

void Application::run()
{
    this->initialize();
    this->main_loop();
}

void Application::initialize()
{
    SDL_Init(SDL_INITIALIZATION_FLAGS);
    this->game_window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    this->world = new WorldController(this->game_window->get_window_surface());
    this->world->populate_matrix();
    this->player = new Player(100, 100, 100);
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
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    world->check_mouse_click({mouse_x, mouse_y}, this->player);
                }
                break;                
            }
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_e)
                {
                    this->world->mark_tile_for_construction();
                }
                break;
            }          
        }
    }
}

void Application::draw()
{
    SDL_FillRect(this->game_window->get_window_surface(), NULL, color_from_rgb(83, 93, 94, 255));
    this->world->draw();

    SDL_UpdateWindowSurface(this->game_window->get_object());
}

void Application::destroy()
{
    delete this->game_window;
    delete this->world;
    delete this->player;
}