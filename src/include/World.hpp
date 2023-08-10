#ifndef _WORLD_HPP
#define _WORLD_HPP

#include <optional>
#include "constants.hpp"
#include "Player.hpp"
#include "defs.hpp"
#include <SDL2/SDL.h>
#include <array>


class GameObject;
enum class GameObjectType;
class GOTree;

// Name: [selected]?, [selected_side]?, [shape]?, [top], [down]
enum class TileType
{
    GRASS_DIRT,
    SELECTED_GRASS_DIRT,
    SELECTED_LEFT_GRASS_DIRT,
    SELECTED_RIGHT_GRASS_DIRT,
};

struct WorldTile
{
    TileType type;
    int rel_x;
    int rel_y;
    SDL_Rect* absolute_position;
    std::optional<GameObject*> child;
};



#endif