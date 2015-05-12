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
    m_elapsedTime=0;
    m_fireRate = DEFAULT_SHOT_FIRERATE;
}

// -- moveP -------------------------------------
// Moves the player
// ----------------------------------------------
void Player::moveP(Event event, float timedelta)
{
    /*
    int choice;
    cout <<endl;
    cout << "1 : Gauche"<<endl;
    cout << "2 : Droite"<<endl;
    cin >> choice;*/
    if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Left))
    {
        if ((getX()-getX_speed()*timedelta)> 0)
        {
            setX(getX()-getX_speed()*timedelta);
        }
        else if((getX()-getX_speed()*timedelta)< 0)
        {
            setX(0);
        }
    }
    else if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Right))
    {
        if ((getX()+getW()+getX_speed()*timedelta)< MODEL_WIDTH)
        {
            setX(getX()+getX_speed()*timedelta);
        }
        else if((getX()+getW()+getX_speed()*timedelta)> MODEL_WIDTH)
        {
            setX(MODEL_WIDTH-getW());
        }
    }
}

// -- shoot -------------------------------------
// Makes the player shoot
// ----------------------------------------------
void Player::shoot(float timedelta)
{
    m_elapsedTime += timedelta;
    if (m_elapsedTime>m_fireRate)
    {
        Shot* shot = new Shot(m_styleShot, (getX()+getW()/2), getY(), 0, -200);
        shots.push_back(shot);
        m_elapsedTime=0;
    }
}
