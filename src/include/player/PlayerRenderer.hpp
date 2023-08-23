#ifndef _PLAYER_RENDERER_HPP
#define PLAYER_RENDERER_HPP

#include <SDL2/SDL.h>

class PlayerRenderer
{
public:
    void draw(SDL_Surface* surface, int x, int y);
};

#endif