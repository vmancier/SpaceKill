#include <iostream>
#include "Ship.hpp"

using namespace std;

Ship::Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, int damages, Shot shot, int style)
{
    m_x= x;
    m_y=y;
    m_w=w;
    m_h=h;
    m_x_speed=x_speed;
    m_y_speed=y_speed;
    m_health=health;
    m_damages=damages;
    m_shot=shot;
    m_style=style;
    m_alive = true;
}

Ship::Ship()
{
    m_x= 200;
    m_y=10;
    m_w=1;
    m_h=1;
    m_x_speed=0;
    m_y_speed=0;
    m_health=100;
    m_damages=0;
    m_style=0;
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

int Ship::getStyle()
{
    return m_style;
}

int Ship::getLife()
{
    return m_life;
}

int Ship::getDamages()
{
    return m_damages;
}

bool Ship::getAlive()
{
    return m_alive;
}

float Ship::getHealth()
{
    return m_health;
}

int Ship::getX()
{
    return m_x;
}

int Ship::getY()
{
    return m_y;
}
