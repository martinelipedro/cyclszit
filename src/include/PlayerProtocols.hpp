#ifndef _PLAYER_PROTOCOLS_HPP
#define _PLAYER_PROTOCOLS_HPP

#include "Item.hpp"

#include <vector>

struct ReceiveItemsProtocol
{
    std::vector<ItemStack*> item_stack_list;
};

#endif