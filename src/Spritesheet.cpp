#include "include/Spritesheet.hpp"

Spritesheet::Spritesheet(const char* _filepath, unsigned int _row_size, unsigned int _column_size)
{
    this->spritesheet_image = SDL_LoadBMP(_filepath);

    this->clip.w =  _column_size;
    this->clip.h =  _row_size;
}

Spritesheet::~Spritesheet()
{
    SDL_FreeSurface(this->spritesheet_image);
}

void Spritesheet::select_sprite(unsigned int _x, unsigned int _y)
{
    this->clip.x = _x * this->clip.w;
    this->clip.y = _y * this->clip.h;
}

void Spritesheet::draw_selected(SDL_Surface* _window_surface, SDL_Rect* _position)
{
    SDL_BlitSurface(this->spritesheet_image, &this->clip, _window_surface, _position);
}