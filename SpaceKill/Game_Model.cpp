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
    Level(8);
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
void Game_Model::nextStep()
{
    createEnemy();
    getEnemyPos();
    //shootEnemy();
    m_player->shot();
    //m_player->getShotsPos();
    //moveShots();
    //moveEnemies();
    //getPlayerPos();
}

// -- Play --------------------------------------
// Says if the game is playing or not
// * out-parameters :
// - result, boolean : says if the game is playing or no
// ----------------------------------------------
bool Game_Model::Play()
{
    bool result = false;
    if(m_player->getAlive())
    {
        result = true;
    }
    return result;
}

// -- Level -------------------------------------
// Creates a level according to the current state of game
// ----------------------------------------------
void Game_Model::Level(int levelStyle)
{
    _levelStyle = levelStyle;

    /*switch(m_levelStyle)
    {
    case 1:
        m_
    }*/
}

// -- createEnemy -------------------------------
// Creates an enemy according to his style
// ----------------------------------------------
void Game_Model::createEnemy()
{
    int exactWidth = MODEL_WIDTH - ENEMY_WIDTH;
    int xPos = rand() % exactWidth;
    int style = getLevelNumber();

    Enemy *monEnemiTest = new Enemy(xPos, style);
    enemies.push_back(monEnemiTest);
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
void Game_Model::shootEnemy()
{

    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->shoot();
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
    x= m_player->getX();
    y= m_player->getY();
    w= m_player->getW();
    h= m_player->getH();
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
