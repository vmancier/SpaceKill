#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Shot
{
private:
    float m_damageP;
    float m_fireRate;
    int m_style;
    bool m_collision;
public:
    Shot();
    Shot(int style, float fireRate, float damageP);
    bool collision();
};

#endif // SHOT_HPP_INCLUDED
