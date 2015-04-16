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
    m_player = new Player(_w/2, _h-10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED, 100, 0);
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

// -- getPlayerPos ------------------------------
// Returns the player's position
// ----------------------------------------------
void Game_Model::getPlayerPos() const
{
    int x = m_player->getX();
    int y = m_player->getY();
    cout << endl<< "Joueur(" << x << "," << y << ")" << endl;
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

// -- nextStep ----------------------------------
// Runs the next step
// ----------------------------------------------
void Game_Model::nextStep()
{
    createEnemy();
    getEnemyPos();
    shootEnemy();
    m_player->shot();
    m_player->getShotsPos();
    moveShots();
    moveEnemies();
    getPlayerPos();
    m_player->moveP();

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

// -- createEnemy -------------------------------
// Creates an enemy
// ----------------------------------------------
void Game_Model::createEnemy()
{

    int xPos = rand() % MODEL_WIDTH;
    Enemy *myEnemy = new Enemy(xPos, 10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, 40, 100, 0, 10, 0);
    enemies.push_back(myEnemy);
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

// -- moveEnemies ---------------------------------
// Moves the enemies
// ----------------------------------------------
void Game_Model::moveEnemies()
{
    for(unsigned int i = 0; i<enemies.size(); i++)
    {
        enemies[i]->moveForward();
        if ( enemies[i]->getY()> MODEL_HEIGHT )
        {
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
    }
}


void Game_Model::Level(int levelStyle)
{

}
