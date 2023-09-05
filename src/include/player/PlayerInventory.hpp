#ifndef _PLAYER_INVENTORY_HPP
#define _PLAYER_INVENTORY_HPP

#include "../item/Item.hpp"
#include <map>

using PlayerInventory = std::map<ItemType, ItemStack*>;

#endif