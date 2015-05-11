/********************************************************************************************
 * Project: SpaceKill
 * File: Enemy.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED
#include "Ship.hpp"

class Enemy : public Ship
{
private:
    int m_style;
    int m_value;
    int styleShot;

public:
    Enemy();
    Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int value, int styleShot, int style);
    Enemy(int x, int style);

    void moveForward(float timedelta);
    void shoot();
    void setEnemySettings(int style, float coef);
    int getStyle() const;

};

#endif // ENEMY_HPP_INCLUDED
