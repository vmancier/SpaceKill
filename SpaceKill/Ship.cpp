#include <iostream>
#include "Ship.hpp"

using namespace std;

Ship::Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, Shot shot)
            : m_x(x), m_y(y), m_w(w), m_h(h), m_x_speed(x_speed), m_y_speed(y_speed), m_health(health), m_shot(shot)
{
    m_alive = true;
}

Ship::Ship()
{
    m_x=200;
    m_y=10;
    m_w=1;
    m_h=1;
    m_x_speed=0;
    m_y_speed=0;
    m_health=100;
    m_alive = true;
}

void Ship::loseLife(int damages)
{
    if (m_health > damages)
    {
        m_health -= damages;
    }
    else if (m_health == damages)
    {
        m_health =100;
        m_life--;
    }
    else
    {
        m_life--;
        int tmp = m_health-damages;
        m_health=100-tmp;
    }
}

void Ship::shoot()
{

}

void Ship::die()
{
    if (m_life==0)
    {
        m_alive =false;
    }
}

int Ship::getLife()
{
    return m_life;
}

bool Ship::getAlive()
{
    return m_alive;
}

float Ship::getHealth()
{
    return m_health;
}

void Ship::setX(int x)
{
    m_x = x;
}

void Ship::setY(int y)
{
    m_y = y;
}

int Ship::getX()
{
    return m_x;
}

int Ship::getY()
{
    return m_y;
}

int Ship::getW()
{
    return m_w;
}

int Ship::getH()
{
    return m_h;
}

int Ship::getX_speed()
{
    return m_x_speed;
}

int Ship::getY_speed()
{
    return m_y_speed;
}
