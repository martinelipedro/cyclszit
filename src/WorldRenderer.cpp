#include "include/WorldRenderer.hpp"
#include "include/GameObject.hpp"


SDL_Rect* get_sprite_absolute_position(int x, int y)
{
    SDL_Rect* position = new SDL_Rect{WORLD_OFFSET_X + ((x * TILE_WIDTH / 2) - (y * TILE_WIDTH / 2)), WORLD_OFFSET_Y + ((y * TILE_HEIGHT /2) + (x * TILE_HEIGHT / 2)), 0, 0};
    return position;
}

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