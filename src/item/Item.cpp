#include "../include/item/Item.hpp"

ItemStack::ItemStack(ItemType type, unsigned int quantity) : frame{type, quantity} {}

void ItemStack::add_item(unsigned int quantity)
{
    this->frame.quantity += quantity;
}

void ItemStack::remove_item(unsigned int quantity)
{
    this->frame.quantity -= quantity;
    if (this->frame.quantity < 0) this->frame.quantity = 0;
}