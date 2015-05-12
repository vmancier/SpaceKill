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
    float _spawnRate;
    Player * m_player;
    std::vector<Enemy*> enemies;

public:
    Game_Model();
    Game_Model(int w, int h);
    ~Game_Model();

    void nextStep();
    bool Play();
    void Level(int levelStyle);
    void createEnemy();
    void moveEnemies(float timedelta);
    void shootEnemy(float timedelta);
    void moveShots(float timedelta);
    int getLevelNumber() const;

    Player* getPlayer() const;
    void getPlayerPos() const;
    void getPlayerSettings(int &x, int &y, int &w, int &h) const;

    Enemy* getEnemy(int nb) const;
    int getEnemiesSize() const;
    void getEnemyPos() const;
    void getEnemySettings(int &x, int &y, int &w, int &h, int i) const;
};

#endif // GAME_MODEL_HPP_INCLUDED
