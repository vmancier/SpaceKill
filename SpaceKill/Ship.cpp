#include <iostream>
#include "Ship.hpp"

using namespace std;

//Ship::Ship()
//{

//}

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
