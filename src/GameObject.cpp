#include "include/GameObject.hpp"
#include "include/constants.hpp"

#include <iostream>

GameObject::GameObject(GameObjectType type, WorldTile* parent, bool breakable, bool interactive)
    : type(type), parent(parent), breakable(breakable), interactive(interactive) {}
   
GOTree::GOTree(GameObjectType type, WorldTile* parent) : GameObject(type, parent, true, false) {}

void GOTree::handle(std::function<void(ReceiveItemsProtocol*, Player*)> callback, Player* player)
{
    ReceiveItemsProtocol* protocol = new ReceiveItemsProtocol{
        std::vector<ItemStack*>{new ItemStack(ItemType::WOOD, 5)}
    };
    callback(protocol, player);
}

void GOTree::draw(SDL_Surface* window_surface, Spritesheet* spritesheet) 
{
    spritesheet->select_sprite(4, 0);
    SDL_Rect* position = new SDL_Rect{ parent->absolute_position->x , parent->absolute_position->y - TILE_HEIGHT, 0, 0};
    spritesheet->draw_selected(window_surface, position);
}