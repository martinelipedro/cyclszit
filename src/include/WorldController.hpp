#ifndef _WORLD_CONTROLLER_HPP
#define _WORLD_CONTROLLER_HPP

#include "World.hpp"
#include "WorldRenderer.hpp"
#include <memory>

class WorldController
{
private:
    std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix;

    bool selected_tile_exists() const;
    Vec2<int> get_selected_tile_relative_position() const;
    void set_tile_type_and_adjacents(WorldTile* tile, TileType type);
    void clear_tile_type(WorldTile* tile);
    bool is_point_inside_area(Vec2<int> point) const;

public:
    std::optional<WorldTile*> selected_tile;
    std::unique_ptr<WorldRenderer> renderer;


    WorldController(SDL_Surface* window_surface);
    // TODO: generate world chunks randomly
    void populate_matrix();
    void reset_selected();
    void mark_tile_for_construction();
    void check_mouse_click(SDL_Point mouse_position);
    void draw();
};


#endif