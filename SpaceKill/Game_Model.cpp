#include <iostream>
#include "Game_Model.hpp"
#include "Entities.hpp"

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
    //m_player = new Player(w/2, 10, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_X_SPEED, PLAYER_Y_SPEED);
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
        // Deplacement du joueur

    }
}

bool Game_Model::Play()
{
    bool result = false;
    if(m_player->getLife())
    {
        result =true;
    }
    return result;
}
