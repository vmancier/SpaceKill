#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED

class Enemy : public Ship
{
private:
    int m_lifeE = 1;
    int m_value;
public:
    Enemy();
    Enemy(int style, int life, int value);
    void moveForward();
};

#endif // ENEMY_HPP_INCLUDED
