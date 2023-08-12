#include "include/helpers.hpp"
#include "include/constants.hpp"
#include "include/defs.hpp"

SDL_Point* get_absolute_position(int x, int y)
{
    SDL_Point* position = new SDL_Point{WORLD_OFFSET_X + ((x * TILE_WIDTH / 2) - (y * TILE_WIDTH / 2)), WORLD_OFFSET_Y + ((y * TILE_HEIGHT /2) + (x * TILE_HEIGHT / 2))};
    return position;
}

SDL_Point* get_relative_position(int x, int y)
{
    SDL_Point* position = new SDL_Point{};

    float sx = x - WORLD_OFFSET_X;
    float sy = y - WORLD_OFFSET_Y;
    float relative_x = round(((sx / TILE_WIDTH) + (sy / TILE_HEIGHT)) - 1);
    float relative_y = round(((sy / TILE_HEIGHT) - (sx / TILE_WIDTH)));
    position->x = relative_x;
    position->y = relative_y;
    return position;
}