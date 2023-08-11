#ifndef _WORLD_RENDERER_HPP
#define _WORLD_RENDERER_HPP

#include "Spritesheet.hpp"
#include "defs.hpp"
#include <SDL2/SDL.h>
#include "constants.hpp"
#include <optional>
#include <array>



#include "World.hpp"


class WorldRenderer
{
private:
    SDL_Surface* window_surface;
    Spritesheet* spritesheet;

    void select_sprite(TileType type);
public:
    WorldRenderer(SDL_Surface* window_surface);

    void draw(std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix);
};

#endif