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
    //m_player->shot();
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
    int x_speed = 0;
    int y_speed = 0;
    int health = 0;
    int styleShot = 0;
    int m_value = 0;
    int m_w = 0;
    int m_h = 0;
    switch(style)
    {
    case 1:
        x_speed = 100;
        y_speed = 100;
        health = 100;
        styleShot = 1;
        m_value = 10;
        m_w = 36;
        m_h = 64;
        break;
    case 2:
        x_speed = 120;
        y_speed = 120;
        health = 120;
        styleShot = 2;
        m_value = 15;
        m_w = 31;
        m_h = 45;
        break;
    case 3:
        x_speed = 140;
        y_speed = 140;
        health = 140;
        styleShot = 3;
        m_value = 20;
        m_w = 51;
        m_h = 53;
        break;
    case 4:
        x_speed = 160;
        y_speed = 160;
        health = 160;
        styleShot = 4;
        m_value = 25;
        m_w = 31;
        m_h = 60;
        break;
    case 5:
        x_speed = 180;
        y_speed = 180;
        health = 180;
        styleShot = 5;
        m_value = 30;
        m_w = 31;
        m_h = 60;
        break;
    case 6:
        x_speed = 200;
        y_speed = 200;
        health = 200;
        styleShot = 6;
        m_value = 35;
        m_w = 50;
        m_h = 50;
        break;
    case 7:
        x_speed = 220;
        y_speed = 220;
        health = 220;
        styleShot = 7;
        m_value = 40;
        m_w = 44;
        m_h = 60;
        break;
    case 8:
        x_speed = 240;
        y_speed = 240;
        health = 120;
        styleShot = 8;
        m_value = 45;
        m_w = 50;
        m_h = 50;
        break;
    }
    Enemy *myEnemy = new Enemy(xPos, 10, m_w, m_h, x_speed, y_speed, health, m_value, styleShot, style);
    enemies.push_back(myEnemy);
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
void Game_Model::moveShots()
{
    m_player->moveShotsShip();
    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->moveShotsShip();
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
