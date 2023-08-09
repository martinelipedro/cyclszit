#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

class Window
{
private:
    SDL_Window* window_object;
    SDL_Surface* window_surface_object;
    bool open;
public:
    Window(uint16_t width, uint16_t height, const std::string& title);
    Window(uint16_t width, uint16_t height, const char* title);

    bool is_open() const;
    void close();


    SDL_Surface* get_window_surface() const;
    SDL_Window* get_object() const;
};

#endif