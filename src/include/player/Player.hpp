#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "PlayerRenderer.hpp"
#include "PlayerInventory.hpp"

class Player
{
public:
    unsigned int max_life, current_life;
    unsigned int max_hunger, current_hunger;
    unsigned int max_thirst, current_thirst;
    int player_x;
    int player_y;
    PlayerRenderer* renderer;
public:
    PlayerInventory inventory;
    Player(unsigned int max_life, unsigned int max_hunger, unsigned int max_thist);
    void draw(SDL_Surface* screen_surface);
};

#endif