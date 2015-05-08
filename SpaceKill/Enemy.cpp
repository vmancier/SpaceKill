/********************************************************************************************
 * Project: SpaceKill
 * File: Enemy.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Enemy.hpp"
#include "Entities.hpp"

using namespace std;

// -- Enemy -------------------------------------
// Builds by default an object "enemy"
// * out-parameters :
// - "enemy", object : the enemy itself
// ----------------------------------------------
Enemy::Enemy()
{
    m_value = 0;
}

// -- Enemy -------------------------------------
// Builds an object "enemy"
// * in-parameters :
// - "x", int : horizontal position of the enemy
// - "y", int : vertical position of the enemy
// - "w", int : width of the enemy
// - "h", int : height of the enemy
// - "x_speed", float : horizontal speed of the enemy
// - "y_speed", float : horizontal speed of the enemy
// - "health", int : level of the enemy's health
// - "style", int : number of the enemy's style
// - "value", int : A COMPLETEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEER
// - "styleShot" : number of the enemy's shoot's style
// ----------------------------------------------
Enemy::Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int style, int value, int styleShot)
    :Ship(x, y, w, h, x_speed, y_speed, health, styleShot), m_style(style), m_value(value)
{

}

// -- moveForward -------------------------------
// Moves the enemy forward
// * out-parameters :
// - m_y, int : modified enemy's position
// ----------------------------------------------
void Enemy::moveForward(float timedelta)
{
    m_y += m_y_speed*timedelta;
}

// -- getStyle ----------------------------------
// Gets the number of the enemy's style
// * out-parameters :
// - "m_style", int : number of the enemy's style
// ----------------------------------------------
int Enemy::getStyle() const
{
    return m_style;
}

// -- shoot -------------------------------------
// Makes the enemy shoot
// ----------------------------------------------
void Enemy::shoot()
{
    Shot* shot = new Shot(m_styleShot, ((getX()+getW())/2), ((getY()+getH())/2), 0, 53);
    shots.push_back(shot);
}
