#include "include/WorldController.hpp"
#include "include/GameObject.hpp"
#include <iostream>

#include "include/helpers.hpp"

WorldController::WorldController(SDL_Surface* window_surface)
{
    this->renderer = new WorldRenderer(window_surface);
    this->selected_tile = std::nullopt;
}

// TODO: generate world chunks randomly
void WorldController::populate_matrix()
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            WorldTile* tile = new WorldTile {
                TileType::GRASS_DIRT,
                new SDL_Point{i, j},
                get_absolute_position(i, j),
                std::nullopt,
                std::nullopt,
                std::nullopt
            };
            this->area_matrix[i][j] = tile;
        }
    }

    this->area_matrix[1][1]->child = new GOTree(GameObjectType::Tree, this->area_matrix[1][1]);
}

void WorldController::reset_selected()
{
    if (!this->selected_tile.has_value())
        return;

    SDL_Point* relative_position = this->selected_tile.value()->relative_position;
    if (this->area_matrix[relative_position->x][relative_position->y]->type != TileType::SELECTED_GRASS_DIRT)
        return;

    this->area_matrix[relative_position->x][relative_position->y]->type = TileType::GRASS_DIRT;
    if (relative_position->y < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x][relative_position->y + 1]->type = TileType::GRASS_DIRT;
    }
    if (relative_position->x < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x + 1][relative_position->y]->type = TileType::GRASS_DIRT;
    }  
}

void WorldController::mark_tile_for_construction()
{
    if (!this->selected_tile.has_value())
        return;
    
    SDL_Point* relative_position = this->selected_tile.value()->relative_position;
    this->area_matrix[relative_position->x][relative_position->y]->type = TileType::CONSTRUCTION_GRASS_DIRT;
    if (relative_position->y < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x][relative_position->y + 1]->type = TileType::CONSTRUCTION_RIGHT_GRASS_DIRT;
    }
    if (relative_position->x < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x + 1][relative_position->y]->type = TileType::CONSTRUCTION_LEFT_GRASS_DIRT;
    }  
}

void WorldController::check_mouse_click(SDL_Point mouse_position, Player* player)
{
    bool event_handled = false;
    this->reset_selected();
    for (auto& _ : area_matrix)
    {   
        for (auto& tile : _)
        {
            SDL_Point* position = get_relative_position(mouse_position.x, mouse_position.y);
            
            if (position->y >= 0 && position->y < MATRIX_SIZE && position->x >= 0 && position->x < MATRIX_SIZE)
            {
                this->selected_tile = area_matrix[position->x][position->y];
                if (area_matrix[position->x][position->y]->child.has_value() && !event_handled)
                {
                    static_cast<GOTree*>(area_matrix[position->x][position->y]->child.value())->handle(receive_item_callback, player);
                    event_handled = true;
                }
                area_matrix[position->x][position->y]->type = TileType::SELECTED_GRASS_DIRT;
                if (position->y < MATRIX_SIZE - 1)
                {
                    area_matrix[position->x][position->y + 1]->type = TileType::SELECTED_RIGHT_GRASS_DIRT;
                }
                if (position->x < MATRIX_SIZE - 1)
                {
                    area_matrix[position->x + 1][position->y]->type = TileType::SELECTED_LEFT_GRASS_DIRT;
                }  
            }   
        }
    }  
}

void WorldController::draw()
{
    this->renderer->draw(area_matrix);
}