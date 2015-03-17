#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

class Ship
{
private:
    virtual int m_life;
    Shot m_shot;
    int m_damages;
    float m_percentageLife; // nom approximatif,  au départ :niveauVie
    bool m_alive;
public:
    void loseLife(int damages);
    void shoot();
    void die();
};
#endif // SHIP_HPP_INCLUDED
