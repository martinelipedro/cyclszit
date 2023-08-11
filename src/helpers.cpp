#include "include/helpers.hpp"
#include "include/constants.hpp"
#include "include/defs.hpp"

SDL_Rect* get_sprite_absolute_position(int x, int y)
{
    SDL_Rect* position = new SDL_Rect{WORLD_OFFSET_X + ((x * TILE_WIDTH / 2) - (y * TILE_WIDTH / 2)), WORLD_OFFSET_Y + ((y * TILE_HEIGHT /2) + (x * TILE_HEIGHT / 2)), 0, 0};
    return position;
}