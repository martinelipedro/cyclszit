#include "include/Item.hpp"

ItemStack::ItemStack(ItemType type, unsigned int quantity) : type(type), quantity(quantity)
{

}

void ItemStack::add_item(unsigned int quantity)
{
    this->quantity += quantity;
}

void ItemStack::remove_item(unsigned int quantity)
{
    this->quantity -= quantity;
    if (this->quantity < 0) this->quantity = 0;
}