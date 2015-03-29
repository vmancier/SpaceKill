#include <iostream>
#include "Enemy.hpp"
#include "Entities.hpp"

#include "cstdlib"  //necessaire pour le rand() du x


using namespace std;

Enemy::Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, Shot shot, int style, int value)
      :Ship(x, y, w, h, x_speed, y_speed, health, shot), m_style(style), m_value(value)
{
    //shot.setPosition(int style, int x, int y, int w, int h)
}

Enemy::Enemy():Ship()
{
    m_value=0;
}

int Enemy::getStyle()
{
    return m_style;
}

void createEnemy()
{
    //generer un enemi grace au constructeur, en lui passant comme parametres un y fixe (le haut de l'ecran), et un x random
    //Enemy monEnemiTest(int x=rand() % MODEL_WIDTH, getY, MODEL_WIDTH, MODEL_HEIGHT, x_speed, y_speed, health, Shot shot, style, value);
}
