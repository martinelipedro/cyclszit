#ifndef _WORLD_HPP
#define _WORLD_HPP

#include <optional>
#include "Spritesheet.hpp"
#include "constants.hpp"

#include "Player.hpp"
#include <array>

class GameObject;
enum class GameObjectType;
class GOTree;

#include "defs.hpp"

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

class World
{
private:
    std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix;
    Spritesheet tile_spritesheet;

    SDL_Rect* get_sprite_position(int x, int y);
    void select_sprite(TileType tile);
public:
    World();
    // TODO: generate world chunks randomly
    void populate_matrix();
    void reset_selected();
    void check_mouse_click(SDL_Point mouse_position, Player* player);
    void draw(SDL_Surface* window_surface);
};

#endif