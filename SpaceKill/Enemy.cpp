#include <iostream>
#include "Enemy.hpp"

using namespace std;

Enemy::Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, Shot shot, int style, int value)
      :Ship(x, y, w, h, x_speed, y_speed, health, shot), m_style(style), m_value(value)
{

}

Enemy::Enemy():Ship()
{
    m_value=0;
}

int Enemy::getStyle()
{
    return m_style;
}
