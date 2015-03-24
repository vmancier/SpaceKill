#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Ship;

class Shot
{
private:
    float m_damageP;
    float m_fireRate;
    int m_style;
    bool m_collision;
public:
    Shot();
    Shot(int style);
    void shotSettings(int style);
    bool collision(Ship &s);

};

#endif // SHOT_HPP_INCLUDED
