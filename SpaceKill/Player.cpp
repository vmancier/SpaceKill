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
    Shot* shot =new Shot(m_styleShot,(getX()+getW())/2 ,(getY()+getH())/2,-20, 0);
    shots.push_back(shot);
}
