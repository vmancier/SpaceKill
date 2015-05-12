/********************************************************************************************
 * Project: SpaceKill
 * File: Ship.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Entities.hpp"
#include "Shot.hpp"
#include <vector>

class Shot;

class Ship
{
protected:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    float m_x_speed;
    float m_y_speed;
    float m_health;
    int m_styleShot;
    float m_fireRate;
    float m_elapsedTime;
    int m_life;
    bool m_alive;
    std::vector <Shot*> shots;

public:
    Ship();
    Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health,int styleShot);
    ~Ship();

    void loseLife(int damages);
    void die();
    void moveShotsShip(float timedelta);

    void setFireRate();
    void setX(int x);
    void setY(int y);
    Shot* getShot(int nb) const;
    void getShotsPos();
    void getShotSettings(int &x, int &y, int &w, int &h, int i) const;
    int getShotsSize() const;
    int getLife() const;
    bool getAlive() const;
    float getHealth() const;
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getX_speed() const;
    int getY_speed() const;


};
#endif // SHIP_HPP_INCLUDED
