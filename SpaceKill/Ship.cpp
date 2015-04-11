#include <iostream>
#include "Ship.hpp"

using namespace std;

Ship::Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_x_speed(x_speed), m_y_speed(y_speed), m_health(health), m_styleShot(styleShot)
{
    m_alive = true;
}

Ship::Ship()
{
    m_x=200;
    m_y=10;
    m_w=1;
    m_h=1;
    m_x_speed=20.0;
    m_y_speed=0;
    m_health=100;
    m_alive = true;
}

Ship::~Ship()
{
    for(int i=0; i<shots.size(); i++)
    {
        delete shots[i];
    }
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

void Ship::die()
{
    if (m_life==0)
    {
        m_alive =false;
    }
}

void Ship::getShotsPos()
{
    for(int i=0; i<shots.size(); i++)
    {
        int x=shots[i]->getX();
        int y=shots[i]->getY();
        cout << "Tir("<<x<<","<<y<<")"<<endl;
    }
}

void Ship::moveShotsShip()
{
    for(int i=0; i<shots.size(); i++)
    {
        shots[i]->moveShot();
        if ( shots[i]->getX()< 0 || (shots[i]->getX())> MODEL_WIDTH || shots[i]->getY()< 0 || shots[i]->getY()> MODEL_HEIGHT )
        {
            delete shots[i];
            shots.erase(shots.begin()+i);
        }
    }
}

int Ship::getLife() const
{
    return m_life;
}

bool Ship::getAlive()const
{
    return m_alive;
}

float Ship::getHealth() const
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

int Ship::getX() const
{
    return m_x;
}

int Ship::getY() const
{
    return m_y;
}

int Ship::getW() const
{
    return m_w;
}

int Ship::getH() const
{
    return m_h;
}

int Ship::getX_speed() const
{
    return m_x_speed;
}

int Ship::getY_speed() const
{
    return m_y_speed;
}
