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
    m_player = new Player(_w/2, _h-10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED, 100, 0);
}

//=======================================
// Destructeurs
//=======================================
Game_Model::~Game_Model()
{
     for(int i=0; i<enemies.size(); i++)
    {
        delete enemies[i];
    }
}

//=======================================
// Accesseurs en lecture
//=======================================
void Game_Model::getPlayerPos() const
{
    int x=m_player->getX();
    int y=m_player->getY();
    cout << "Joueur("<<x<<","<<y<<")"<<endl<<endl;
}

void Game_Model::getEnemyPos() const
{
    for(int i=0; i<enemies.size(); i++)
    {
        int x=enemies[i]->getX();
        int y=enemies[i]->getY();
        cout << "Ennemi("<<x<<","<<y<<")"<<endl;
    }
    cout <<endl;
}
//=======================================
// Calcul la prochaine étape
//=======================================
void Game_Model::nextStep()
{
    createEnemy();
    getPlayerPos();
    getEnemyPos();
    shootEnemy();
    m_player->shot();
    m_player->getShotsPos();
    moveShots();
    moveEnemies();
    m_player->moveP();
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
    Enemy *monEnemiTest= new Enemy(xPos,10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, 40, 100, 0,10,0);
    enemies.push_back(monEnemiTest);
}

void Game_Model::shootEnemy()
{
    for(int i=0; i<enemies.size(); i++)
    {
        enemies[i]->shoot();
        enemies[i]->getShotsPos();
    }
}

void Game_Model::moveShots()
{
    m_player->moveShotsShip();
    for(int i=0; i<enemies.size(); i++)
    {
        enemies[i]->moveShotsShip();
    }
}

void Game_Model::moveEnemies()
{
     for(int i=0; i<enemies.size(); i++)
    {
        enemies[i]->moveForward();
        if ( enemies[i]->getY()> MODEL_HEIGHT )
        {
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
    }
}

void Game_Model::Level(int levelStyle) {

}
