/********************************************************************************************
 * Project: SpaceKill
 * File: Game_Model.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef GAME_MODEL_HPP_INCLUDED
#define GAME_MODEL_HPP_INCLUDED

#include "Player.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"

#include <vector>

class Game_Model
{
private:
    int _w, _h;
    int _levelStyle;
    Player * m_player;
    std::vector<Enemy*> enemies;

public:
    Game_Model();
    Game_Model(int w, int h);
    ~Game_Model();

    void nextStep();
    bool Play();
    void getPlayerPos() const;
    void getEnemyPos() const;
    void getPlayerSettings(int &x, int &y, int &w, int &h) const;
    void createEnemy();
    void shootEnemy();
    void moveShots();
    void moveEnemies();
    void Level(int levelStyle);
};

#endif // GAME_MODEL_HPP_INCLUDED
