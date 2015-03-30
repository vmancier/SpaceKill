#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

//#include "Shot.hpp"

//class Shot;

class Ship
{
private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    float m_x_speed;
    float m_y_speed;
    float m_health;
    int m_styleShot;
    int m_life;
    bool m_alive;
public:
    Ship();
    Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health,int styleShot);
    void loseLife(int damages);
    void shoot();
    void die();
    int getLife() const;
    bool getAlive() const;
    float getHealth() const;
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getX_speed() const;
    int getY_speed() const;
};
#endif // SHIP_HPP_INCLUDED
