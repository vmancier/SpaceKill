#include <iostream>
#include "Game_Model.hpp"
#include "Entities.hpp"

#include <cstdlib>  //necessaire pour le rand() du x

using namespace std;

//=======================================
// Constructeurs
//=======================================
Game_Model::Game_Model(): _w(MODEL_WIDTH), _h(MODEL_HEIGHT)
{
    m_player = new Player();
}
//=======================================
Game_Model::Game_Model(int w, int h):  _w(w), _h(h)
{
    m_player = new Player();
    //m_player = new Player(w/2, 10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED,100,30,shot,style);
}

//=======================================
// Destructeurs
//=======================================
Game_Model::~Game_Model()
{
    //if(_ball != NULL)
    //delete _ball;
}

//=======================================
// Accesseurs en lecture
//=======================================
void Game_Model::getPlayerPos(int &x, int &y) const
{
    x=m_player->getX();
    y=m_player->getY();
}
//=======================================
// Calcul la prochaine étape
//=======================================
void Game_Model::nextStep()
{
    if(m_player != NULL)
    {
        //getPlayerPos();

    }
    createEnemy(); //<<<<<<<<<<<<<<<<<<<<---------LA FUITE MEMOIRE EST LA

}

bool Game_Model::Play()
{
    bool result = false;
    if(m_player->getAlive())
    {
        result =true;
    }
    return result;
}

void Game_Model::createEnemy()
{
    int xPos=rand() % MODEL_WIDTH;
    Enemy *monEnemiTest= new Enemy(xPos,10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED, 100, 0,10,0);
    //Enemy(int x, int y, int w, int h, float x_speed, float y_speed, int health, int style, int value, int styleShot)
}
