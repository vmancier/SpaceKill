/********************************************************************************************
 * Project: SpaceKill
 * File: Shot.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Shot.hpp"
#include "Entities.hpp"

using namespace std;

// -- Shot --------------------------------------
// Builds by default an object "shot"
// ----------------------------------------------
Shot::Shot()
{
    m_xS = 0;
    m_yS = 0;
    m_wS = 10;
    m_hS = 30;
    m_x_speedS = 50;
    m_y_speedS = 0;
    m_damage = 30.0;
    //m_fireRate = DEFAULT_SHOT_FIRERATE;
    m_style = 0;
}

// -- Shot --------------------------------------
// Builds an object "shot"
// * in-parameters :
// - "style" : number of the ship's shoot's style
// - "x", int : horizontal position of the shot
// - "y", int : vertical position of the shot
// - "xSpeed", float : horizontal speed of the shot
// - "ySpeed", float : horizontal speed of the shot
// ----------------------------------------------
Shot::Shot(int style, int x, int y, int xSpeed, int ySpeed)
{
    m_style = style;
    switch(style)
    {
    case 1:
        m_damage = 30.0;
        break;
    case 2:
        m_damage = 40.0;
        break;
    case 3:
        m_damage = 50.0;
        //m_fireRate = 1.05;
        break;
    case 4:
        m_damage = 60.0;
        //m_fireRate = 1.20;
        break;
    case 5:
        m_damage = 70.0;
        //m_fireRate = 1.32;
        break;
    case 6:
        m_damage = 80.0;
        //m_fireRate = 1.50;
        break;
    }
    m_xS = x;
    m_yS = y;
    m_wS = 10;
    m_hS = 30;
    m_x_speedS = xSpeed;
    m_y_speedS = ySpeed;
}

// -- moveShot ----------------------------------
// Moves the shot
// ----------------------------------------------
void Shot::moveShot(float timedelta)
{
    m_xS += m_x_speedS *timedelta;
    m_yS += m_y_speedS *timedelta;
}

// -- getStyle ----------------------------------
// Returns the shoot's style
// ----------------------------------------------
int Shot::getStyle() const
{
    return m_style;
}

// -- getDamages --------------------------------
// Returns the shoot's damages
// ----------------------------------------------
int Shot::getDamages() const
{
    return m_damage;
}

// -- getX --------------------------------------
// Returns the horizontal shoot's position
// ----------------------------------------------
int Shot::getX() const
{
    return m_xS;
}

// -- getY --------------------------------------
// Returns the vertical shoot's position
// ----------------------------------------------
int Shot::getY() const
{
    return m_yS;
}

// -- getW --------------------------------------
// Returns the shot's width
// ----------------------------------------------
int Shot::getW() const
{
    return m_wS;
}

// -- getH --------------------------------------
// Returns the shot's height
// ----------------------------------------------
int Shot::getH() const
{
    return m_hS;
}
