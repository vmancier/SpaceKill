/********************************************************************************************
 * Project: SpaceKill
 * File: Player.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Ship.hpp"

class Player : public Ship
{
private:
    int m_scoreP;
public:
    Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot);
    Player();
    ~Player();
    void moveP();
    void shot();
};
#endif // PLAYER_HPP_INCLUDED
