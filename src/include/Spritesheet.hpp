#ifndef _SPRITESHEET_HPP
#define _SPRITESHEET_HPP

#define ORIGINAL_SPRITE_SIZE 16
#define SPRITE_SCALE 2
#define SPRITE_SIZE ORIGINAL_SPRITE_SIZE * SPRITE_SCALE
#include <SDL2/SDL.h>

class Spritesheet
{
private:

public:
    SDL_Rect clip;
    SDL_Surface* spritesheet_image;
    Spritesheet(const char* filepath, unsigned int row_size, unsigned int column_size);
    ~Spritesheet();

    void select_sprite(unsigned int x, unsigned int y);
    void draw_selected(SDL_Surface* window_surface, SDL_Rect* position);
};

#endif