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
    int m_w;
    int m_h;
    float m_x_speed;
    float m_y_speed;
public:
    Ship();
    Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, int damages, Shot m_shot, int m_style);
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
