/********************************************************************************************
 * Project: SpaceKill
 * File: Game_Model.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Game_Model.hpp"
#include "Entities.hpp"
#include "Game_View.hpp"

#include <cstdlib>  //necessaire pour le rand() du x
#include <math.h>

using namespace std;

// -- Game_Model --------------------------------
// Builds by default an object "game_model"
// * out-parameters :
// - "game_model", object : the game model itself
// ----------------------------------------------
Game_Model::Game_Model(): _w(MODEL_WIDTH), _h(MODEL_HEIGHT)
{
    m_player = new Player();
    Level(0);
    _levelProgress=0;
    _lastSpawn=0;
    m_score = 0;
}

// -- Game_Model --------------------------------
// Builds an object "game_model"
// * in-parameters :
// - w, int : width of the game model
// - h, int : height of the game model
// * out-parameters :
// - "game_model", object : the game model itself
// ----------------------------------------------
Game_Model::Game_Model(int w, int h): _w(w), _h(h)
{
    m_player = new Player((_w/2)-(PLAYER_WIDTH/2), _h-(2*PLAYER_HEIGHT), PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED, 100, 0);
    Level(0);
    _levelProgress=0;
    m_score=0;
    _level_change = false;
}

// -- ~Game_Model --------------------------------
// Deletes the object "game_model"
// ----------------------------------------------
Game_Model::~Game_Model()
{
    for(unsigned int i=0; i<enemies.size(); i++)
    {
        delete enemies[i];
        enemies.clear();
    }
}

// -- nextStep ----------------------------------
// Runs the next step
// ----------------------------------------------
void Game_Model::nextStep(float timedelta)
{
    createEnemy(timedelta);
    shootEnemy(timedelta);
    m_player->shoot(timedelta);
    moveShots(timedelta);
    moveEnemies(timedelta);
    collisions();
    loadLevel();
}

void Game_Model::loadLevel()
{
    if (_levelProgress >=LEVEL_DURATION)
    {
        _levelStyle++;
        _levelProgress=0;
        _lastSpawn=0;
        for(unsigned int i=0; i<enemies.size(); i++)
        {
            delete enemies[i];
        }
        enemies.clear();
        Level(_levelStyle);
        m_player->setStyleShot(m_player->getStyleShot()+1);
        _level_change = true;
    }
}
// -- Level -------------------------------------
// Creates a level according to the current state of game
// ----------------------------------------------
void Game_Model::Level(int levelStyle)
{
    float tmp=0;
    int level =levelStyle%LEVELS;
    switch(level)
    {
    case 0:
        tmp = SPAWNRATE_0;
        break;
    case 1:
        tmp = SPAWNRATE_1;
        break;
    case 2:
        tmp = SPAWNRATE_2;
        break;
    case 3:
        tmp = SPAWNRATE_3;
        break;
    case 4:
        tmp = SPAWNRATE_4;
        break;
    case 5:
        tmp = SPAWNRATE_5;
        break;
    case 6:
        tmp = SPAWNRATE_6;
        break;
    case 7:
        tmp = SPAWNRATE_7;
        break;
    }
    _spawnRateMax=tmp/log(_levelStyle+1);
    _spawnRate=((float) rand()*tmp) / ((float) RAND_MAX)+ tmp;
    _lastSpawn=_spawnRate;
}

// -- createEnemy -------------------------------
// Creates an enemy according to his style
// ----------------------------------------------
void Game_Model::createEnemy(float timedelta)
{
    _levelProgress+=timedelta;
    _lastSpawn+=timedelta;
    if (_lastSpawn >=_spawnRate)
    {
        int exactWidth = MODEL_WIDTH - DEFAULT_ENEMY_WIDTH;
        int xPos = rand() % exactWidth;
        int style = getLevelNumber()%LEVELS;
        Enemy *myEnemy = new Enemy(xPos, style);
        enemies.push_back(myEnemy);
        _lastSpawn=0;
    }
}

// -- moveEnemies -------------------------------
// Moves the enemies
// ----------------------------------------------
void Game_Model::moveEnemies(float timedelta)
{
    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->moveForward(timedelta);
        if ( enemies[i]->getY()> MODEL_HEIGHT )
        {
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
    }
}

// -- shootEnemy --------------------------------
// Makes the enemy shoot
// ----------------------------------------------
void Game_Model::shootEnemy(float timedelta)
{
    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->shoot(timedelta);
    }
}

// -- moveShots ---------------------------------
// Moves the shots
// ----------------------------------------------
void Game_Model::moveShots(float timedelta)
{
    m_player->moveShotsShip(timedelta);
    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->moveShotsShip(timedelta);
    }
}

// -- getLevelNumber ----------------------------
// Returns the current level's number
// ----------------------------------------------
int Game_Model::getLevelNumber() const
{
    return _levelStyle;
}

void Game_Model::collisions()
{
    /*collisions between enemies and player's shots*/
    for(int i=0; i<m_player->getShotsSize(); i++)
    {
        for(unsigned int j=0; j<enemies.size(); j++)
        {
            if (collision(m_player,enemies[j],i))
            {
                enemies[j]->loseLife(m_player->getShot(i)->getDamages());
                if (enemies[j]->die())
                {
                    m_score +=enemies[j]->getValue();
                    delete enemies[j];
                    enemies.erase(enemies.begin()+j);
                }
                delete m_player->getShot(i);
                m_player->eraseShot(i);
            }
        }
    }
    /*collisions between player and enemies's shots*/
    for(unsigned int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<enemies[j]->getShotsSize(); i++)
        {
            if (collision(enemies[j],m_player,i))
            {
                m_player->loseLife((enemies[j]->getShot(i))->getDamages());
                if (m_player->die()==true)
                {
                    delete m_player;
                }
                delete enemies[j]->getShot(i);
                enemies[j]->eraseShot(i);
            }
        }
    }
}

bool Game_Model::collision(const Ship* a, const Ship* b, int i)
{
    int x, y, w, h;
    bool coll = true;
    a->getShotSettings(x, y, w, h, i);
    int leftShot = x;
    int rightShot = x+w;
    int topShot = y;
    int bottomShot = y+h;

    int leftShip = b->getX();
    int rightShip = leftShip + b->getW();
    int topShip = b->getY();
    int bottomShip = topShip + b->getH();
    if(bottomShot <= topShip || leftShot >= rightShip || topShot >= bottomShip || rightShot <= leftShip)
    {
        coll =false;
    }
    return coll;
}

// -- getPlayer ---------------------------------
// Returns the player
// ----------------------------------------------
Player* Game_Model::getPlayer() const
{
    return m_player;
}

// -- getPlayerSetings --------------------------
// Returns the player's position and size
// ----------------------------------------------
void Game_Model::getPlayerSettings(int &x, int &y, int &w, int &h) const
{
    x = m_player->getX();
    y = m_player->getY();
    w = m_player->getW();
    h = m_player->getH();
}

// -- getEnemy ----------------------------------
// Returns a specified enemy
// ----------------------------------------------
Enemy* Game_Model::getEnemy(int nb) const
{
    return enemies[nb];
}

// -- getEnemiesSize ----------------------------
// Returns the size of the vector "enemies", so the number of enemies
// ----------------------------------------------
int Game_Model::getEnemiesSize() const
{
    return enemies.size();
}

// -- getEnemySettings --------------------------
// Returns the enemy's position and size
// ----------------------------------------------
void Game_Model::getEnemySettings(int &x, int &y, int &w, int &h, int i) const
{
    x = enemies[i]->getX();
    y = enemies[i]->getY();
    w = enemies[i]->getW();
    h = enemies[i]->getH();
}

int Game_Model::getScore() const
{
    return m_score;
}

bool Game_Model::getLevelChange() const
{
    return _level_change;
}

void Game_Model::setLevelChange(bool level_change)
{
    _level_change = level_change;
}
