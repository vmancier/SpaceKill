#include <iostream>
#include "Player.hpp"
#include "Ship.hpp"

using namespace std;

Player::Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
       :Ship(x, y, w, h, x_speed, y_speed, health, styleShot)
{

}

Player::Player():Ship()
{

}


void Player::moveP()
{
    int choice;
    cout <<endl;
    cout << "1 : Gauche"<<endl;
    cout << "2 : Droite"<<endl;
    cin >> choice;
    if(choice==1)
    {
        setX(getX()-getX_speed());
    }
    else if(choice ==2)
    {
        setX(getX()+getX_speed());
    }
    else
    {
        moveP();
    }
}

void Player::shot()
{
    Shot* shot =new Shot();
    shot->setPosition(0,getX(),getY(),getW(),getH());
    shot->setSpeed(-2,0);
    shots.push_back(shot);
}
