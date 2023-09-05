#include "../include/player/player_event_callbacks.hpp"

#include <iostream>

void receive_item_callback(ReceiveItemsProtocol* protocol, Player* player)
{
    for (auto item : protocol->item_stack_list)
    {
        player->inventory[item->frame.type]->frame.quantity += item->frame.quantity;
    }
}
