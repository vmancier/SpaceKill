#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include "Ship.hpp"

class Player : public Ship
{
private:
    int m_scoreP;
public:
    Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int damages, Shot m_shot, int m_style);
    Player();
    ~Player();
    void moveP();
};
#endif // PLAYER_HPP_INCLUDED
