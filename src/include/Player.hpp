#ifndef _PLAYER_HPP
#define _PLAYER_HPP

class Player
{
private:
    unsigned int max_life, current_life;
    unsigned int max_hunger, current_hunger;
    unsigned int max_thirst, current_thirst;
public:
    Player(unsigned int max_life, unsigned int max_hunger, unsigned int max_thist);

    unsigned int wood_qt;
};


#endif