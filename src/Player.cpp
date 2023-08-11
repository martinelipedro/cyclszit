#include "include/Player.hpp"

Player::Player(unsigned int max_life, unsigned int max_hunger, unsigned int max_thist) 
    : max_life(max_life), max_hunger(max_hunger), max_thirst(max_thirst), \
    current_life(max_life), current_hunger(max_hunger), current_thirst(max_thirst) {}
