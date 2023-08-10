#ifndef _WORLD_HPP
#define _WORLD_HPP

#include <optional>

#include "constants.hpp"
#include "WorldRenderer.hpp"
#include "Player.hpp"
#include <array>

class GameObject;
enum class GameObjectType;
class GOTree;

#include "defs.hpp"

// Name: [selected]?, [selected_side]?, [shape]?, [top], [down]




class World
{
private:
    std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix;

public:
    WorldRenderer* renderer;

    World(SDL_Surface* get_window_surface);
    // TODO: generate world chunks randomly
    void populate_matrix();
    void reset_selected();
    void check_mouse_click(SDL_Point mouse_position, Player* player);
    void draw();
};

#endif