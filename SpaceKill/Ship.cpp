/********************************************************************************************
 * Project: SpaceKill
 * File: Ship.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Ship.hpp"

using namespace std;

// -- Ship --------------------------------------
// Builds by default an object "ship"
// ----------------------------------------------
Ship::Ship()
{
    m_x = 200;
    m_y = 10;
    m_w = 1;
    m_h = 1;
    m_x_speed = 20.0;
    m_y_speed = 0;
    m_health = 100;
    m_alive = true;
}

// -- Ship --------------------------------------
// Builds an object "ship"
// * in-parameters :
// - "x", int : horizontal position of the ship
// - "y", int : vertical position of the ship
// - "w", int : width of the ship
// - "h", int : height of the ship
// - "x_speed", float : horizontal speed of the ship
// - "y_speed", float : horizontal speed of the ship
// - "health", int : level of the ship's health
// - "styleShot" : number of the ship's shoot's style
// ----------------------------------------------
Ship::Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_x_speed(x_speed), m_y_speed(y_speed), m_health(health), m_styleShot(styleShot)
{
    m_alive = true;
    m_fireRate = DEFAULT_SHOT_FIRERATE;
}

// -- ~Ship -------------------------------------
// Deletes the object "ship"
// ----------------------------------------------
Ship::~Ship()
{
    for(unsigned int i = 0; i<shots.size(); i++)
    {
        delete shots[i];
    }
}

// -- loseLife ----------------------------------
// Makes the ship lose a part of his life
// * in-parameters :
// - "damages", int : amount of damages
// ----------------------------------------------
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
        m_health = 100-tmp;
    }
}

// -- die ---------------------------------------
// Makes the ship die
// ----------------------------------------------
void Ship::die()
{
    if (m_life == 0)
    {
        m_alive = false;
    }
}

// -- moveShotsShip -----------------------------
// Moves the ship's shots
// ----------------------------------------------
void Ship::moveShotsShip(float timedelta)
{
    for(unsigned int i=0; i<shots.size(); i++)
    {
        shots[i]->moveShot(timedelta);
        if ( shots[i]->getX()< 0 || (shots[i]->getX())> MODEL_WIDTH || shots[i]->getY()< 0 || shots[i]->getY()> MODEL_HEIGHT )
        {
            delete shots[i];
            shots.erase(shots.begin()+i);
        }
    }
}

void Ship::setFireRate()
{

}

// -- setX --------------------------------------
// Sets the horizontal ship's position
// ----------------------------------------------
void Ship::setX(int x)
{
    m_x = x;
}

// -- setY --------------------------------------
// Sets the vertical ship's position
// ----------------------------------------------
void Ship::setY(int y)
{
    m_y = y;
}

// -- getShot -----------------------------------
// Returns a specified shot
// ----------------------------------------------
Shot* Ship::getShot(int nb) const
{
    return shots[nb];
}

// -- getShotPos --------------------------------
// Returns the shot's position
// ----------------------------------------------
void Ship::getShotsPos()
{
    for(unsigned int i=0; i<shots.size(); i++)
    {
        int x = shots[i]->getX();
        int y = shots[i]->getY();
        cout << "Tir(" << x << "," << y << ")" << endl;
    }
}

// -- getShotSettings ---------------------------
// Return the shot's position and size
// ----------------------------------------------
void Ship::getShotSettings(int &x, int &y, int &w, int &h, int i) const
{
    x = shots[i]->getX();
    y = shots[i]->getY();
    w = shots[i]->getW();
    h = shots[i]->getH();
}

// -- getShotsSize ------------------------------
// Returns the size of the vector "shots", so the number of shots
// ----------------------------------------------
int Ship::getShotsSize() const
{
    return shots.size();
}

// -- getLife -----------------------------------
// Returns the ship's life
// ----------------------------------------------
int Ship::getLife() const
{
    return m_life;
}

// -- getAlive ----------------------------------
// Returns the ship's state
// ----------------------------------------------
bool Ship::getAlive()const
{
    return m_alive;
}

// -- getHealth ---------------------------------
// Returns the ship's health
// ----------------------------------------------
float Ship::getHealth() const
{
    return m_health;
}

// -- getX --------------------------------------
// Returns the horizontal ship's position
// ----------------------------------------------
int Ship::getX() const
{
    return m_x;
}

// -- getY --------------------------------------
// Returns the vertical ship's position
// ----------------------------------------------
int Ship::getY() const
{
    return m_y;
}

// -- getW --------------------------------------
// Returns the ship's width
// ----------------------------------------------
int Ship::getW() const
{
    return m_w;
}

// -- getH --------------------------------------
// Returns the ship's height
// ----------------------------------------------
int Ship::getH() const
{
    return m_h;
}

// -- getX_speed -------------------------------
// Returns the horizontal ship's speed
// ----------------------------------------------
int Ship::getX_speed() const
{
    return m_x_speed;
}

// -- getY_speed -------------------------------
// Returns the vertical ship's speed
// ----------------------------------------------
int Ship::getY_speed() const
{
    return m_y_speed;
}
