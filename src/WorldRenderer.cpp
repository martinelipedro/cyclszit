#include "include/WorldRenderer.hpp"
#include "include/GameObject.hpp"

WorldRenderer::WorldRenderer(SDL_Surface* window_surface) 
    : window_surface(window_surface), spritesheet(new Spritesheet(constants::path_terrain_tileset, 128, 128)) {}


void WorldRenderer::select_sprite(TileType type)
{
     if (type == TileType::SELECTED_GRASS_DIRT)
    {
        this->spritesheet->select_sprite(1, 0);
    }
    else if (type == TileType::SELECTED_LEFT_GRASS_DIRT)
    {
        this->spritesheet->select_sprite(2, 0);
    }
    else if (type == TileType::SELECTED_RIGHT_GRASS_DIRT)
    {
        this->spritesheet->select_sprite(3, 0);
    }
    else
    {
        this->spritesheet->select_sprite(0, 0);
    }
}

void WorldRenderer::draw(std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix)
{
    for (auto& _ : area_matrix)
    {   
        for (auto& tile : _)
        {
            this->select_sprite(tile->type);
            this->spritesheet->draw_selected(window_surface, tile->absolute_position);
            if (tile->child.has_value())
            {
                tile->child.value()->draw(window_surface, this->spritesheet);
            }
        }
    } 
}