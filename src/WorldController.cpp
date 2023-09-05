#include "include/WorldController.hpp"
#include <iostream>

#include "include/helpers.hpp"

WorldController::WorldController(SDL_Surface* window_surface)
{
    this->renderer = std::make_unique<WorldRenderer>(WorldRenderer(window_surface));
    this->selected_tile = std::nullopt;
}

bool WorldController::selected_tile_exists() const
{
    return this->selected_tile.has_value();
}

SDL_Point* WorldController::get_selected_tile_relative_position() const
{
    return this->selected_tile.value()->relative_position;
}

void WorldController::set_tile_type_and_adjacents(WorldTile* tile, TileType type)
{
    SDL_Point* relative_position = tile->relative_position;
    this->area_matrix[relative_position->x][relative_position->y]->type = type;
    if (relative_position->y < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x][relative_position->y + 1]->type = static_cast<TileType>(static_cast<int>(type) + 2);
    }
    if (relative_position->x < MATRIX_SIZE - 1)
    {
        area_matrix[relative_position->x + 1][relative_position->y]->type = static_cast<TileType>(static_cast<int>(type) + 1);
    }  
}

void WorldController::clear_tile_type(WorldTile* tile)
{   
    SDL_Point* relative_position = tile->relative_position;
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

bool WorldController::is_point_inside_area(SDL_Point* point) const
{
    return point->y >= 0 && point->y < MATRIX_SIZE && point->x >= 0 && point->x < MATRIX_SIZE;
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
            };
            this->area_matrix[i][j] = tile;
        }
    }
}

void WorldController::reset_selected()
{
    if (!this->selected_tile_exists())
        return;

    SDL_Point* relative_position = this->get_selected_tile_relative_position();
    if (this->area_matrix[relative_position->x][relative_position->y]->type != TileType::SELECTED_GRASS_DIRT)
        return;

    this->clear_tile_type(this->selected_tile.value());
    this->selected_tile = std::nullopt;
}

void WorldController::mark_tile_for_construction()
{
    if (!this->selected_tile_exists())
        return;

    this->set_tile_type_and_adjacents(this->selected_tile.value(), TileType::CONSTRUCTION_GRASS_DIRT);
}

void WorldController::check_mouse_click(SDL_Point mouse_position)
{
    this->reset_selected();
    SDL_Point* relative_mouse_position = get_relative_position(mouse_position.x, mouse_position.y);
    
    if (!this->is_point_inside_area(relative_mouse_position))
        return;

    this->selected_tile = area_matrix[relative_mouse_position->x][relative_mouse_position->y];
    this->set_tile_type_and_adjacents(this->selected_tile.value(), TileType::SELECTED_GRASS_DIRT);
}

void WorldController::draw()
{
    this->renderer->draw(area_matrix);
}
