#include "../include/item/Recipe.hpp"
#include <algorithm>

template <RecipeType T_Type, int T_IngredientCount>
bool recipe_is_craftable(const Recipe<T_Type, T_IngredientCount> recipe, std::vector<ItemFrame> ingredients)
{
    if (ingredients.size() < recipe.ingredients.size()) return false;

    std::sort(recipe.ingredients.begin(), recipe.ingredients.end());
    std::sort(ingredients.begin(), ingredients.end());
    return std::includes(ingredients.begin(), ingredients.end(), recipe.ingredients.begin(), recipe.ingredients.end());
}

template <RecipeType T_Type, int T_IngredientCount>
bool craft_recipe(const Recipe<T_Type, T_IngredientCount> recipe, std::vector<ItemFrame> ingredients, PlayerInventory* player_inventory)
{
    if (!recipe_is_craftable<T_Type, T_IngredientCount>(recipe, ingredients))
    {
        return false;
    }
}
