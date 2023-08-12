#include "include/WorldRenderer.hpp"
#include "include/GameObject.hpp"

WorldRenderer::WorldRenderer(SDL_Surface* window_surface) 
    : window_surface(window_surface), spritesheet(new Spritesheet(constants::path_terrain_tileset, 128, 128)) {}


void WorldRenderer::select_sprite(TileType type)
{
    switch (type)
    {
        case TileType::SELECTED_GRASS_DIRT: this->spritesheet->select_sprite(1, 0); break;
        case TileType::SELECTED_LEFT_GRASS_DIRT: this->spritesheet->select_sprite(2, 0); break;
        case TileType::SELECTED_RIGHT_GRASS_DIRT: this->spritesheet->select_sprite(3, 0); break;
        case TileType::CONSTRUCTION_GRASS_DIRT: this->spritesheet->select_sprite(5, 0); break;
        case TileType::CONSTRUCTION_LEFT_GRASS_DIRT: this->spritesheet->select_sprite(6, 0); break;
        case TileType::CONSTRUCTION_RIGHT_GRASS_DIRT: this->spritesheet->select_sprite(7, 0); break;
        default: this->spritesheet->select_sprite(0, 0); break;
    }
}

void WorldRenderer::draw(std::array<std::array<WorldTile*, MATRIX_SIZE>, MATRIX_SIZE> area_matrix)
{
    for (auto& _ : area_matrix)
    {   
        for (auto& tile : _)
        {
            this->select_sprite(tile->type);
            SDL_Rect* draw_rect = new SDL_Rect{tile->absolute_position->x, tile->absolute_position->y, 0, 0};
            this->spritesheet->draw_selected(window_surface, draw_rect);
            if (tile->child.has_value())
            {
                tile->child.value()->draw(window_surface, this->spritesheet);
            }

            delete draw_rect;
        }
    } 
}