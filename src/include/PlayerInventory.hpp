#ifndef _PLAYER_INVENTORY_HPP
#define _PLAYER_INVENTORY_HPP

#include "Item.hpp"
#include <map>

struct PlayerInventory
{
    std::map<ItemType, ItemStack*> data;
};

#endif