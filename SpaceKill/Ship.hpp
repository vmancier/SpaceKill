#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Shot.hpp"

class Ship
{
private:
    virtual int m_life;
    int m_style;
    Shot m_shot;
    int m_damages;
    float m_percentageLife; // nom approximatif,  au d�part :niveauVie
    bool m_alive;
    int m_x;
    int m_y;
public:
    void loseLife(int damages);
    void shoot();
    void die();
};
#endif // SHIP_HPP_INCLUDED
