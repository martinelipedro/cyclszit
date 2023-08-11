#include "include/GameObject.hpp"
#include "include/constants.hpp"

#include <iostream>

void receive_item_callback(ReceiveItemsProtocol* protocol, Player* player)
{
    player->wood_qt += protocol->item_stack_list[0]->quantity;
    std::cout << player->wood_qt << '\n';
}

GameObject::GameObject(GameObjectType type, WorldTile* parent, bool breakable, bool interactive)
    : type(type), parent(parent), breakable(breakable), interactive(interactive) {}
   
GOTree::GOTree(GameObjectType type, WorldTile* parent) : GameObject(type, parent, true, false) {}

