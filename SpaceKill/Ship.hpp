#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Shot.hpp"

class Shot;

class Ship
{
private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    float m_x_speed;
    float m_y_speed;
    float m_health;
    Shot m_shot;
    int m_life;
    bool m_alive;
public:
    Ship();
    Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, Shot shot);
    void loseLife(int damages);
    void shoot();
    void die();
    int getLife();
    bool getAlive();
    float getHealth();
    int getX();
    int getY();
    int getW();
    int getH();
};
#endif // SHIP_HPP_INCLUDED
