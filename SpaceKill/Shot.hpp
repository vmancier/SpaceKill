#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Ship;

class Shot
{
private:
    int m_style;
    float m_damageP;
    float m_fireRate;
    bool m_collision;
public:
    Shot();
    Shot(int style);
    void shotSettings(int style);
    bool collision(Ship &s);
    int getStyle();
    int getDamages();

};

#endif // SHOT_HPP_INCLUDED
