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
// - "value", int : number of points won by the player when he shots the enemy
// - "styleShot" : number of the enemy's shoot's style
// ----------------------------------------------
Enemy::Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int value, int styleShot, int style)
    :Ship(x, y, w, h, x_speed, y_speed, health, styleShot), m_style(style), m_value(value)
{
    m_fireRate = DEFAULT_SHOT_FIRERATE;
    m_direction=DEFAULT_ENEMY_DIRECTION;
    m_elapsedTime=0;
}

Enemy::Enemy(int x, int style)
{
    m_style = style;
    m_elapsedTime=0;
    m_direction=DEFAULT_ENEMY_DIRECTION;
    m_fireRate = DEFAULT_SHOT_FIRERATE;
    switch(style)
    {
    case 0:
        Enemy::setEnemySettings( COEF_0);
        break;
    case 1:
        Enemy::setEnemySettings( COEF_1);
        break;
    case 2:
        Enemy::setEnemySettings( COEF_2);
        break;
    case 3:
        Enemy::setEnemySettings( COEF_3);
        break;
    case 4:
        Enemy::setEnemySettings( COEF_4);
        break;
    case 5:
        Enemy::setEnemySettings( COEF_5);
        break;
    case 6:
        Enemy::setEnemySettings( COEF_6);
        break;
    case 7:
        Enemy::setEnemySettings( COEF_7);
        break;
    }
    m_x = x;
    m_currentHealth=m_healthMax;
}

void Enemy::setEnemySettings(float coef)
{
    m_x_speed = DEFAULT_ENEMY_X_SPEED*coef;
    m_y_speed = DEFAULT_ENEMY_X_SPEED*coef;
    m_healthMax = DEFAULT_ENEMY_HEALTH*coef;
    m_life =1;
    m_styleShot = DEFAULT_ENEMY_STYLESHOT*coef;
    m_value = DEFAULT_ENEMY_VALUE*coef;
    m_w = DEFAULT_ENEMY_WIDTH;
    m_h = DEFAULT_ENEMY_HEIGHT;
    m_y = (-m_h);
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

int Enemy::getValue() const
{
    return m_value;
}
