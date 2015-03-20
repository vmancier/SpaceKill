#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Shot.hpp"

class Shot;

class Ship
{
private:
    int m_life;
    int m_style;
    Shot m_shot;
    int m_damages;
    float m_health;
    bool m_alive;
    int m_x;
    int m_y;
public:
    Ship();
    void loseLife(int damages);
    void shoot();
    void die();
    int getStyle();
    int getLife();
    int getDamages();
    bool getAlive();
    float getHealth();
    int getX();
    int getY();
};
#endif // SHIP_HPP_INCLUDED
