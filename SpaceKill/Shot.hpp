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
    bool collision();
};

#endif // SHOT_HPP_INCLUDED
