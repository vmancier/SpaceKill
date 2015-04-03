#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED
#include "Ship.hpp"

class Enemy : public Ship
{
private:
    int m_style;
    int m_value;

public:
    Enemy();
    Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int style, int value, int styleShot);
    void moveForward();
    int getStyle()const;
    void shoot();
};

#endif // ENEMY_HPP_INCLUDED
