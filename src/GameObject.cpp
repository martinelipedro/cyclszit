#include "include/GameObject.hpp"
#include "include/constants.hpp"

GameObject::GameObject(GameObjectType type, WorldTile* parent, bool breakable, bool interactive)
    : type(type), parent(parent), breakable(breakable), interactive(interactive) {}
   
GOTree::GOTree(GameObjectType type, WorldTile* parent) : GameObject(type, parent, true, false) {}

