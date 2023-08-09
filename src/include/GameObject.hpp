#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include <SDL2/SDL.h>
#include "Spritesheet.hpp"
#include "constants.hpp"
#include "World.hpp"


enum class GameObjectType
{
    Tree,
};

class GameObject
{
public:
    GameObjectType type;
    WorldTile* parent;
    bool breakable;
    bool interactive;

    GameObject(GameObjectType type, WorldTile* parent, bool breakable, bool interactive);
 
    virtual void draw(SDL_Surface* window_surface, Spritesheet* spritesheet) = 0;
};

class GOTree : public GameObject
{
public:
    GOTree(GameObjectType type, WorldTile* parent);
    void draw(SDL_Surface* window_surface, Spritesheet* spritesheet) override
    {
        spritesheet->select_sprite(4, 0);
        SDL_Rect* position = new SDL_Rect{ parent->absolute_position->x , parent->absolute_position->y - TILE_HEIGHT, 0, 0};
        spritesheet->draw_selected(window_surface, position);
    }
};

#endif