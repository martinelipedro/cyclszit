#ifndef _WORLD_HPP
#define _WORLD_HPP

#include "Spritesheet.hpp"

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
    bool selected = false;
};

class World
{
private:
    WorldTile world_matrix[10][10];
    Spritesheet tile_spritesheet;

    SDL_Rect* get_sprite_position(int x, int y);
    void select_sprite(WorldTile& tile);
public:
    World();
    // TODO: generate world chunks randomly
    void populate_matrix();
    void reset_selected();
    void check_mouse_click(SDL_Point mouse_position);
    void draw(SDL_Surface* window_surface);
};

#endif