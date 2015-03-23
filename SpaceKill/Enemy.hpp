#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED
#include "Ship.hpp"

class Enemy : public Ship
{
private:
    int m_value;
public:
    Enemy();
    Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int damages, Shot shot, int style, int value);
    void moveForward();
};

#endif // ENEMY_HPP_INCLUDED
