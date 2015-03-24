#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int damages, Shot shot, int style):Ship(x, y, w, h, x_speed, y_speed, health, damages, shot, style)
{

}

Player::Player():Ship()
{

}

void Player::moveP()
{
    int choice;
    cout << "   1 : Gauche         ";
    cout << "2 : Droite"<<endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    }
}
