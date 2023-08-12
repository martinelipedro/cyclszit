#ifndef _WORLD_CONTROLLER_HPP
#define _WORLD_CONTROLLER_HPP

#include "World.hpp"
#include "WorldRenderer.hpp"

class WorldController
{
private:
    std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix;
public:
    std::optional<WorldTile*> selected_tile;

    WorldRenderer* renderer;

    WorldController(SDL_Surface* get_window_surface);
    // TODO: generate world chunks randomly
    void populate_matrix();
    void reset_selected();
    void check_mouse_click(SDL_Point mouse_position, Player* player);
    void draw();
};


#endif