/********************************************************************************************
 * Project: SpaceKill
 * File: Player.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Player.hpp"
#include "Ship.hpp"
#include "Game_View.hpp"

using namespace std;

using namespace sf;

// -- Player -------------------------------------
// Builds by default an object "player"
// ----------------------------------------------
Player::Player():Ship()
{

}

// -- Player -------------------------------------
// Builds an object "player"
// * in-parameters :
// - "x", int : horizontal position of the player
// - "y", int : vertical position of the player
// - "w", int : width of the player
// - "h", int : height of the player
// - "x_speed", float : horizontal speed of the player
// - "y_speed", float : horizontal speed of the player
// - "health", int : level of the player's health
// - "styleShot" : number of the player's shoot's style
// ----------------------------------------------
Player::Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
    :Ship(x, y, w, h, x_speed, y_speed, health, styleShot)
{
    m_life = DEFAULT_PLAYER_LIFE;
    m_direction=DEFAULT_PLAYER_DIRECTION;
    m_elapsedTime=0;
    m_fireRate = DEFAULT_SHOT_FIRERATE;
}

// -- moveP -------------------------------------
// Moves the player
// ----------------------------------------------
void Player::moveP(bool LeftKeyDown1, bool LeftKeyDown2, bool RightKeyDown1, bool RightKeyDown2, bool UpKeyDown1, bool UpKeyDown2, bool DownKeyDown1, bool DownKeyDown2, float timedelta)
{
    if (LeftKeyDown1 || LeftKeyDown2)
    {
        if (m_x-m_x_speed*timedelta > 0)
        {
            setX(m_x-m_x_speed*timedelta);
        }
        else if(m_x-m_x_speed*timedelta < 0)
        {
            setX(0);
        }
    }

    if (RightKeyDown1 || RightKeyDown2)
    {
        int limit = m_x+m_w+m_x_speed*timedelta;
        if (limit < MODEL_WIDTH)
        {
            setX(m_x+m_x_speed*timedelta);
        }
        else if(limit> MODEL_WIDTH)
        {
            setX(MODEL_WIDTH-m_w);
        }
    }

    if(UpKeyDown1 || UpKeyDown2)
    {
        if (m_y-m_y_speed*timedelta > 0)
        {
            setY(m_y-m_y_speed*timedelta);
        }
        else if (m_y-m_y_speed*timedelta < 0)
        {
            setY(0);
        }
    }

    if(DownKeyDown1 || DownKeyDown2)
    {
        int limit = m_y+m_h+m_y_speed*timedelta;
        if (limit < MODEL_HEIGHT)
        {
            setY(m_y+m_y_speed*timedelta);
        }
        else if (limit > MODEL_HEIGHT)
        {
            setY(MODEL_HEIGHT -m_h);
        }
    }
}
