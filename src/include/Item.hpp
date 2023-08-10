#ifndef _ITEM_HPP
#define _ITEM_HPP

enum class ItemType
{
    WOOD,
};

struct ItemStack
{
    ItemType type;
    unsigned int quantity;

    ItemStack(ItemType type, unsigned int quantity);

    void add_item(unsigned int quantity);
    void remove_item(unsigned int quantity);
};

#endif