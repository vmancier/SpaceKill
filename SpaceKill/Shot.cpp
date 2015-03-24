#include <iostream>
#include "Shot.hpp"

using namespace std;

Shot::Shot()
{
    m_damageP=30.0;
    m_fireRate=0.50;
    m_style=0;
    m_collision=false;
}

Shot::Shot(int style)
{
    m_style= style;
    m_collision=false;
    shotSettings(style);
}

void Shot::shotSettings(int style)
{
    switch(style)
    {
    case 1:
        m_damageP=30.0;
        m_fireRate=0.75;
        break;
    case 2:
        m_damageP=40.0;
        m_fireRate=1.0;
        break;
    case 3:
        m_damageP=50.0;
        m_fireRate=1.05;
        break;
    case 4:
        m_damageP=60.0;
        m_fireRate=1.20;
        break;
    case 5:
        m_damageP=70.0;
        m_fireRate=1.32;
        break;
    case 6:
        m_damageP=80.0;
        m_fireRate=1.50;
        break;
    }
}

bool collision(Ship &s)
{
    /*
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(bottomA <= topB)
        return false;
    if(topA >= bottomB)
        return false;
    if(rightA <= leftB)
        return false;
    if(leftA >= rightB)
        return false;

    return true;
    */
}
int Shot::getStyle()
{
    return m_style;
}

int Shot::getDamages()
{
    return m_damageP;
}

