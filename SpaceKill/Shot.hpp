#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Shot
{
private:

    int m_xS;
    int m_yS;
    int m_wS;
    int m_hS;
    int m_x_speedS;
    int m_y_speedS;
    int m_style;
    float m_damageP;
    float m_fireRate;

public:
    Shot();
    Shot(int style);
    void shotSettings(int style);
    void moveShot();
    int getStyle() const;
    int getDamages() const;
    int getX()const;
    int getY()const;
    void setPosition(int style, int x, int y, int w, int h);
    void setSpeed(int xSpeed, int ySpeed);
};

#endif // SHOT_HPP_INCLUDED
