#include <iostream>
#include "Ship.hpp"

using namespace std;

Ship::Ship()
{

}

void Ship::loseLife(int damages)
{
    if (m_percentageLife > damages)
    {
        m_percentageLife -= damages;
    }
    else if (m_percentageLife == damages)
    {
        m_percentageLife =0;
        m_life--;
    }
    else
    {

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
    return getDamages;
}

bool Ship::getAlive()
{
    return m_alive;
}

float Ship::getPercentageLife()
{
    return m_percentageLife;
}

int Ship::getX()
{
    return m_x;
}

int Ship::die()
{

}

int Ship::getY()
{
    return m_y;
}
