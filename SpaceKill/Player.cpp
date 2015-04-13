#include <iostream>
#include "Player.hpp"
#include "Ship.hpp"

using namespace std;

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

}

// -- moveP -------------------------------------
// Moves the player
// ----------------------------------------------
void Player::moveP()
{
    int choice;
    cout <<endl;
    cout << "1 : Gauche"<<endl;
    cout << "2 : Droite"<<endl;
    cin >> choice;
    if(choice == 1)
    {
        if ((getX()-getX_speed())> 0)
        {
            setX(getX()-getX_speed());
        }
        else if((getX()-getX_speed())< 0)
        {
            setX(0);
        }
    }
    else if(choice == 2)
    {
        setX(getX()+getX_speed());

        if (getX()+getX_speed()< MODEL_WIDTH)
        {
            setX(getX()+getX_speed());
        }
        else if((getX()+getX_speed())> MODEL_WIDTH)
        {
            setX(MODEL_WIDTH);
        }
    }
    else
    {
        moveP();
    }
}

// -- shoot -------------------------------------
// Makes the player shoot
// ----------------------------------------------
void Player::shot()
{
    Shot* shot = new Shot(m_styleShot, (getX()+getW())/2, (getY()+getH())/2, 0, -20);
    shots.push_back(shot);
}
