#include "include/event_callbacks.hpp"

#include <iostream>

void receive_item_callback(ReceiveItemsProtocol* protocol, Player* player)
{
    player->wood_qt += protocol->item_stack_list[0]->quantity;
    std::cout << player->wood_qt << '\n';
}