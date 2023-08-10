#include "include/World.hpp"
#include "include/GameObject.hpp"


World::World() : tile_spritesheet(constants::path_terrain_tileset, SPRITE_SIZE, SPRITE_SIZE)
{
    this->tile_spritesheet.select_sprite(0, 0);
    
}

SDL_Rect* World::get_sprite_position(int x, int y)
{
    SDL_Rect* position = new SDL_Rect{WORLD_OFFSET_X + ((x * TILE_WIDTH / 2) - (y * TILE_WIDTH / 2)), WORLD_OFFSET_Y + ((y * TILE_HEIGHT /2) + (x * TILE_HEIGHT / 2)), 0, 0};
    return position;
}

// TODO: generate world chunks randomly
void World::populate_matrix()
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            WorldTile* tile = new WorldTile {
                TileType::GRASS_DIRT,
                i,
                j,
                this->get_sprite_position(i, j),
                std::nullopt
            };
            this->area_matrix[i][j] = tile;
        }
    }


    this->area_matrix[1][1]->child = new GOTree(GameObjectType::Tree, this->area_matrix[1][1]);
}

void World::reset_selected()
{
    for (auto& _ : area_matrix)
    {
        for (auto& tile : _)
        {
            tile->type = TileType::GRASS_DIRT;
        }
    }
}

#include <iostream>

void World::check_mouse_click(SDL_Point mouse_position, Player* player)
{
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
                if (area_matrix[cursor_x][cursor_y]->child.has_value())
                {
                    static_cast<GOTree*>(area_matrix[cursor_x][cursor_y]->child.value())->handle(receive_item_callback, player);
                }
                area_matrix[cursor_x][cursor_y]->type = TileType::SELECTED_GRASS_DIRT;

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

void World::select_sprite(TileType type)
{
    if (type == TileType::SELECTED_GRASS_DIRT)
    {
        this->tile_spritesheet.select_sprite(1, 0);
    }
    else if (type == TileType::SELECTED_LEFT_GRASS_DIRT)
    {
        this->tile_spritesheet.select_sprite(2, 0);
    }
    else if (type == TileType::SELECTED_RIGHT_GRASS_DIRT)
    {
        this->tile_spritesheet.select_sprite(3, 0);
    }
    else
    {
        this->tile_spritesheet.select_sprite(0, 0);
    }
}

void World::draw(SDL_Surface* window_surface)
{
    for (auto& _ : area_matrix)
    {   
        for (auto& tile : _)
        {
            this->select_sprite(tile->type);
            this->tile_spritesheet.draw_selected(window_surface, tile->absolute_position);
            if (tile->child.has_value())
            {
                tile->child.value()->draw(window_surface, &this->tile_spritesheet);
            }
        }
    } 
}