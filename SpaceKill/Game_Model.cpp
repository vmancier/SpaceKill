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
    Level(1);
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
    m_player = new Player((_w/2)-(PLAYER_WIDTH/2), _h-(2*PLAYER_HEIGHT), PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED, 100, 1);
    Level(3);
    _levelProgress=0;
    _lastSpawn=0;
    m_score=0;
}

// -- ~Game_Model --------------------------------
// Deletes the object "game_model"
// ----------------------------------------------
Game_Model::~Game_Model()
{
    for(unsigned int i=0; i<enemies.size(); i++)
    {
        delete enemies[i];
    }
}

// -- nextStep ----------------------------------
// Runs the next step
// ----------------------------------------------
void Game_Model::nextStep(float timedelta)
{
    createEnemy(timedelta);
    //getEnemyPos();
    //shootEnemy(timedelta);
    m_player->shoot(timedelta);
    //m_player->getShotsPos();
    moveShots(timedelta);
    moveEnemies(timedelta);
    //getPlayerPos();
    collisions();
}

// -- Play --------------------------------------
// Says if the game is playing or not
// * out-parameters :
// - result, boolean : says if the game is playing or no
// ----------------------------------------------
bool Game_Model::Play()
{
    bool result = false;

    return result;
}

// -- Level -------------------------------------
// Creates a level according to the current state of game
// ----------------------------------------------
void Game_Model::Level(int levelStyle)
{
    _levelStyle = levelStyle;
    switch(_levelStyle)
    {
    case 1:
        _spawnRate = 20;
        break;
    case 2:
        _spawnRate = 10.0;
        break;
    case 3:
        _spawnRate = 10.6;
        break;
    case 4:
        _spawnRate = 10.4;
        break;
    case 5:
        _spawnRate = 10.2;
        break;
    case 6:
        _spawnRate = 10.0;
        break;
    case 7:
        _spawnRate = 0.8;
        break;
    case 8:
        _spawnRate = 0.6;
        break;
    }
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
        int style = getLevelNumber();

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
        enemies[i]->getShotsPos();
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
    int x, y, w, h;

    int leftShot, leftShip;
    int rightShot, rightShip;
    int topShot, topShip;
    int bottomShot, bottomShip;
    bool collision;

    /*collisions between enemies and player's shots*/
    for(int i=0; i<m_player->getShotsSize(); i++)
    {
        m_player->getShotSettings(x, y, w, h, i);
        leftShot = x;
        rightShot = x+w;
        topShot = y;
        bottomShot = y+h;

        for(unsigned int j=0; j<enemies.size(); j++)
        {
            leftShip = enemies[j]->getX();
            rightShip = leftShip + enemies[j]->getW();
            topShip = enemies[j]->getY();
            bottomShip = topShip + enemies[j]->getH();
            collision = true;

            if(bottomShot <= topShip || leftShot >= rightShip || topShot >= bottomShip || rightShot <= leftShip)
            {
                collision =false;
            }

            if (collision)
            {
                enemies[j]->loseLife(m_player->getShot(i)->getDamages());
                if (enemies[j]->die())
                {
                    cout <<"ennemi mort"<<endl;
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
    leftShip = m_player->getX();
    rightShip = leftShip + m_player->getW();
    topShip = m_player->getY();
    bottomShip = topShip + m_player->getH();

    for(unsigned int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<enemies[j]->getShotsSize(); i++)
        {
            enemies[j]->getShotSettings(x, y, w, h, i);
            leftShot = x;
            rightShot = x+w;
            topShot = y;
            bottomShot = y+h;
            collision = true;

            if(bottomShot <= topShip || leftShot >= rightShip || topShot >= bottomShip || rightShot <= leftShip)
            {
                collision =false;
            }

            if (collision)
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

// -- getPlayer ---------------------------------
// Returns the player
// ----------------------------------------------
Player* Game_Model::getPlayer() const
{
    return m_player;
}

// -- getPlayerPos ------------------------------
// Returns the player's position
// ----------------------------------------------
void Game_Model::getPlayerPos() const
{
    int x = m_player->getX();
    int y = m_player->getY();
    cout << endl<< "Joueur(" << x << "," << y << ")" << endl;
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

// -- getEnemyPos ------------------------------
// Returns the enemy's position
// ----------------------------------------------
void Game_Model::getEnemyPos() const
{
    for(unsigned int i=0; i<enemies.size(); i++)
    {
        int x = enemies[i]->getX();
        int y = enemies[i]->getY();
        cout << "Ennemi(" << x << "," << y << ")" <<endl;
    }
    cout << endl;
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
