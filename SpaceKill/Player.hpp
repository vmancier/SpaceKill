#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player : public Ship
{
private:
    int m_scoreP;
    int m_lifeP = 3;
public:
    Player();
    Player(int style);
    ~Player();
    void moveP();
};
#endif // PLAYER_HPP_INCLUDED
