#include <iostream>
#include "Shot.hpp"

using namespace std;

Shot::Shot()
{
    m_xS=0;
    m_yS=0;
    m_wS=10;
    m_hS=30;
    m_damageP=30.0;
    m_fireRate=0.50;
    m_style=0;
}

Shot::Shot(int style)
{
    m_style= style;
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

int Shot::getStyle()const
{
    return m_style;
}

int Shot::getDamages()const
{
    return m_damageP;
}

void Shot::setPosition(int style, int x, int y, int w, int h)
{
    switch(style)
    {
    case 0:
        m_xS =x+w/2;//s.getX() + s.getW()/2;
        m_yS =y+h/2;//s.getY() + s.getH()/2;
        break;
    case 1:
        m_xS =x+w/2;//s.getX() + s.getW()/2;
        m_yS =y+h/2;//s.getY() + s.getH()/2;
        break;
    case 2:

        break;

    }

}

