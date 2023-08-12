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
                i,
                j,
                get_sprite_absolute_position(i, j),
                std::nullopt
            };
            this->area_matrix[i][j] = tile;
        }
    }

    this->area_matrix[1][1]->child = new GOTree(GameObjectType::Tree, this->area_matrix[1][1]);
}

void WorldController::reset_selected()
{
    if (this->selected_tile.has_value())
    {
        int rel_x = this->selected_tile.value()->rel_x;
        int rel_y = this->selected_tile.value()->rel_y;

        this->area_matrix[rel_x][rel_y]->type = TileType::GRASS_DIRT;
        if (rel_y < MATRIX_SIZE - 1)
        {
            area_matrix[rel_x][rel_y + 1]->type = TileType::GRASS_DIRT;
        }
        if (rel_x < MATRIX_SIZE - 1)
        {
            area_matrix[rel_x + 1][rel_y]->type = TileType::GRASS_DIRT;
        }  
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
            float sx = mouse_position.x - WORLD_OFFSET_X;
            float sy = mouse_position.y - WORLD_OFFSET_Y;

            float relative_x = ((sx / TILE_WIDTH) + (sy / TILE_HEIGHT)) - 1;
            float relative_y = ((sy / TILE_HEIGHT) - (sx / TILE_WIDTH));
            int cursor_x = round(relative_x);
            int cursor_y = round(relative_y); 
            
            if (cursor_y >= 0 && cursor_y < MATRIX_SIZE && cursor_x >= 0 && cursor_x < MATRIX_SIZE)
            {
                this->selected_tile = area_matrix[cursor_x][cursor_y];
                if (area_matrix[cursor_x][cursor_y]->child.has_value() && !event_handled)
                {
                    static_cast<GOTree*>(area_matrix[cursor_x][cursor_y]->child.value())->handle(receive_item_callback, player);
                    event_handled = true;
                }
                area_matrix[cursor_x][cursor_y]->type = TileType::SELECTED_GRASS_DIRT;
                // player->player_x = cursor_x;
                // player->player_y = cursor_y;

                if (cursor_y < MATRIX_SIZE - 1)
                {
                    area_matrix[cursor_x][cursor_y + 1]->type = TileType::SELECTED_RIGHT_GRASS_DIRT;
                }
                if (cursor_x < MATRIX_SIZE - 1)
                {
                    area_matrix[cursor_x + 1][cursor_y]->type = TileType::SELECTED_LEFT_GRASS_DIRT;
                }  
            }   
        }
    }  
}

void WorldController::draw()
{
    this->renderer->draw(area_matrix);
}