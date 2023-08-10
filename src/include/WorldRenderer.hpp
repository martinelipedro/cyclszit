#ifndef _WORLD_RENDERER_HPP
#define _WORLD_RENDERER_HPP

#include "Spritesheet.hpp"
#include "defs.hpp"
#include <SDL2/SDL.h>
#include "constants.hpp"
#include <optional>
#include <array>

class GameObject;
enum class GameObjectType;
class GOTree;


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





SDL_Rect* get_sprite_absolute_position(int x, int y);

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