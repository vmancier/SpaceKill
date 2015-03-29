#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Ship;

class Shot
{
private:

    int m_xS;
    int m_yS;
    int m_wS;
    int m_hS;

    int m_style;
    float m_damageP;
    float m_fireRate;
    bool m_collision;
public:
    Shot();
    Shot(int style);
    void shotSettings(int style);
    int getStyle();
    int getDamages();
    void setPosition(int style, int x, int y, int w, int h);
};

#endif // SHOT_HPP_INCLUDED
