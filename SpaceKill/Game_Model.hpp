#ifndef GAME_MODEL_HPP_INCLUDED
#define GAME_MODEL_HPP_INCLUDED
#include "Player.hpp"
#include "Enemy.hpp"

class Game_Model
{
private:
    int _w, _h;
    Player * m_player;
public:
    Game_Model();
    Game_Model(int w, int h);
    ~Game_Model();

    void nextStep();
    bool Play();
    void getPlayerPos(int &x, int &y) const;
    void createEnemy();
};

#endif // GAME_MODEL_HPP_INCLUDED
