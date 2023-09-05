#ifndef _WORLD_CONTROLLER_HPP
#define _WORLD_CONTROLLER_HPP

#include "World.hpp"
#include "WorldRenderer.hpp"

#include <memory>

class WorldController
{
private:
    std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix;
    
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