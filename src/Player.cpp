#include "include/Player.hpp"

Player::Player(unsigned int max_life, unsigned int max_hunger, unsigned int max_thirst) 
    : max_life(max_life), max_hunger(max_hunger), max_thirst(max_thirst), \
    current_life(max_life), current_hunger(max_hunger), current_thirst(max_thirst), \
    player_x(7), player_y(7), renderer(new PlayerRenderer) {}

void Player::draw(SDL_Surface* screen_surface)
{
    this->renderer->draw(screen_surface, this->player_x, this->player_y);
}

