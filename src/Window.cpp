#include "include/Window.hpp"
#include <iostream>

void h_check_window_ok(SDL_Window* window_object)
{
    if (!window_object)
    {
        std::cerr << "SDL_Window* object is null" << '\n';
        free(window_object);
        exit(1);
    }
}

void h_check_window_surface_ok(SDL_Surface* window_surface_object)
{
    if (!window_surface_object)
    {
        std::cerr << "SDL_Surface* object of window is null" << '\n';
        std::cerr << "SDL ERROR: " << SDL_GetError() << '\n';
        free(window_surface_object);
        exit(1);
    }
}

Window::Window(uint16_t _width, uint16_t _height, const std::string& _title)
{
    this->window_object = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width,
        _height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
    );
    h_check_window_ok(this->window_object);

    this->window_surface_object = SDL_GetWindowSurface(this->window_object);
    h_check_window_surface_ok(this->window_surface_object);

    this->open = true;
}

Window::Window(uint16_t _width, uint16_t _height, const char* _title)
{
        this->window_object = SDL_CreateWindow(
        _title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width,
        _height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
    );
    h_check_window_ok(this->window_object);
    this->window_surface_object = SDL_GetWindowSurface(this->window_object);
    h_check_window_surface_ok(this->window_surface_object);

    this->open = true;
}

bool Window::is_open() const
{
    return this->open;
}

void Window::close()
{
    this->open = false;
}

SDL_Surface* Window::get_window_surface() const
{
    return this->window_surface_object;
}


SDL_Window* Window::get_object() const
{
    return this->window_object;
}
