#include <iostream>
#include "Enemy.hpp"
#include "Entities.hpp"

using namespace std;

Enemy::Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int style, int value, int styleShot)
      :Ship(x, y, w, h, x_speed, y_speed, health, styleShot), m_style(style), m_value(value)
{

}

Enemy::Enemy():Ship()
{
    m_value=0;
}


int Enemy::getStyle() const
{
    return m_style;
}
