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

    /*cout << "x : " << x
    << "\ny : " << y
    << "\nw : " << w
    << "\nh : " << h
    << "\nx_speed : " << x_speed
    << "\ny_speed : " << y_speed
    << "\nhealth : " << health
    << "\nstyleShot : " << styleShot
    << "\nm_style : " << m_style
    << "\nm_value : " << m_value
    << endl;*/
}

Enemy::Enemy(int x, int style)
{
    m_style = style;
    switch(style)
    {
    case 1:
        m_x_speed = 100;
        m_y_speed = 100;
        m_health = 100;
        m_styleShot = 1;
        m_value = 10;
        m_w = 36;
        m_h = 64;
        break;
    case 2:
        m_x_speed = 120;
        m_y_speed = 120;
        m_health = 120;
        m_styleShot = 2;
        m_value = 15;
        m_w = 31;
        m_h = 45;
        break;
    case 3:
        m_x_speed = 140;
        m_y_speed = 140;
        m_health = 140;
        m_styleShot = 3;
        m_value = 20;
        m_w = 51;
        m_h = 53;
        break;
    case 4:
        m_x_speed = 160;
        m_y_speed = 160;
        m_health = 160;
        m_styleShot = 4;
        m_value = 25;
        m_w = 31;
        m_h = 60;
        break;
    case 5:
        m_x_speed = 180;
        m_y_speed = 180;
        m_health = 180;
        m_styleShot = 5;
        m_value = 30;
        m_w = 31;
        m_h = 60;
        break;
    case 6:
        m_x_speed = 200;
        m_y_speed = 200;
        m_health = 200;
        m_styleShot = 6;
        m_value = 35;
        m_w = 50;
        m_h = 50;
        break;
    case 7:
        m_x_speed = 220;
        m_y_speed = 220;
        m_health = 220;
        m_styleShot = 7;
        m_value = 40;
        m_w = 44;
        m_h = 60;
        break;
    case 8:
        m_x_speed = 240;
        m_y_speed = 240;
        m_health = 120;
        m_styleShot = 8;
        m_value = 45;
        m_w = 50;
        m_h = 50;
        break;
    }
    m_x = x;
}


void Enemy::setEnemySettings(int style)
{
    m_x_speed = DEFAULT_ENEMY_X_SPEED;
    m_y_speed = DEFAULT_ENEMY_X_SPEED;
    m_health = 100;
    m_styleShot = 1;
    m_value = 10;
    m_w = 36;
    m_h = 64;
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

// -- shoot -------------------------------------
// Makes the enemy shoot
// ----------------------------------------------
void Enemy::shoot()
{
    Shot* shot = new Shot(m_styleShot, ((getX()+getW())/2), ((getY()+getH())/2), 0, 53);
    shots.push_back(shot);
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
