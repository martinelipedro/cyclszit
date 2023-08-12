#include "include/Application.hpp"
#include "include/constants.hpp"
#include "include/helpers.hpp"

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
    this->world = new WorldController(this->game_window->get_window_surface());
    this->world->populate_matrix();
    this->player = new Player(100, 100, 100);
    this->status_bar = new UIFStatusBar(30, 30, 40, 150, {255, 255, 255, 255}, {255, 0, 0, 0});
    this->ui_manager = new UIManager;
    this->ui_manager->add_frame(status_bar);
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

void Application::draw_bar(int x, int y, int w, int h, SDL_Color bg, SDL_Color fg, float percent)
{
    SDL_Rect* background_rect = new SDL_Rect {x, y, w, h};
    
    // SDL_FillRect(this->game_window->get_window_surface(), background_rect, color_from_rgb(bg.r, bg.g, bg.b, bg.a));
    // SDL_Rect* border_rect = new SDL_Rect {x + 2, y+ 2, w - 4, h-4};
    // SDL_FillRect(this->game_window->get_window_surface(), border_rect, 0);
    // SDL_Rect* inner_rect = new SDL_Rect {x + 3, static_cast<int>((y + (h - h * percent)) + 3), static_cast<int>(w - 6.f), static_cast<int>(h * percent- 6.f)};
    // SDL_FillRect(this->game_window->get_window_surface(), inner_rect, color_from_rgb(fg.r, fg.g, fg.b, fg.a));
}

void Application::draw()
{
    SDL_FillRect(this->game_window->get_window_surface(), NULL, color_from_rgb(83, 93, 94, 255));
    this->world->draw();
    this->ui_manager->draw(this->game_window->get_window_surface());

    SDL_UpdateWindowSurface(this->game_window->get_object());
}