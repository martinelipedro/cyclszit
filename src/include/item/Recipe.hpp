#ifndef _RECIPE_HPP
#define _RECIPE_HPP

#include <array>
#include <vector>
#include "Item.hpp"
#include "../player/PlayerInventory.hpp"

enum class RecipeType
{
    WOOD_PLANKS,

};

template <RecipeType T_Type, int T_IngredientCount>
struct Recipe
{
    RecipeType type = T_Type;
    std::array<ItemFrame, T_IngredientCount> ingredients{};
};

template <RecipeType T_Type, int T_IngredientCount>
bool recipe_is_craftable(const Recipe<T_Type, T_IngredientCount> recipe, std::vector<ItemFrame> ingredients);

template <RecipeType T_Type, int T_IngredientCount>
bool craft_recipe(const Recipe<T_Type, T_IngredientCount> recipe, std::vector<ItemFrame> ingredients, PlayerInventory* player_inventory);


#endif