#ifndef _WORLD_HPP
#define _WORLD_HPP

#include <optional>
#include "defs.hpp"
#include <SDL2/SDL.h>
#include <array>
#include "vector2.hpp"

// Name: [selected]?, [selected_side]?, [shape]?, [top], [down]
enum class TileType
{
    GRASS_DIRT,
    SELECTED_GRASS_DIRT,
    SELECTED_LEFT_GRASS_DIRT,
    SELECTED_RIGHT_GRASS_DIRT,
    CONSTRUCTION_GRASS_DIRT,
    CONSTRUCTION_LEFT_GRASS_DIRT,
    CONSTRUCTION_RIGHT_GRASS_DIRT,
};

struct WorldTile
{
    TileType type;
    Vec2<int> relative_position;
    Vec2<int> absolute_position;
};

#endif