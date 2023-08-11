#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include <SDL2/SDL.h>
#include <functional>

#include "Spritesheet.hpp"
#include "constants.hpp"
#include "WorldRenderer.hpp"
#include "event_callbacks.hpp"

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
    void handle(std::function<void(ReceiveItemsProtocol*, Player*)> callback, Player* player);
    void draw(SDL_Surface* window_surface, Spritesheet* spritesheet) override;
};

#endif