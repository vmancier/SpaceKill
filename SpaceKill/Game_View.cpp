/********************************************************************************************
 * Project: SpaceKill
 * File: Game_View.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "Game_View.hpp"
#include "Game_Model.hpp"
#include "Entities.hpp"

#include <iostream>

using namespace std;

using namespace sf;

// -- Game_View ---------------------------------
// Builds the game view
// * in-parameters :
// - w, int : width of the window
// - h, int : height of the window
// - bbp, int : number of bits by pixel
// ----------------------------------------------
Game_View::Game_View(int w, int h, int bpp): _w(w), _h(h)
{
    _window = new RenderWindow(sf::VideoMode(w, h, bpp), "SpaceKill", sf::Style::Close);

    if (!_background_image.LoadFromFile("assets/background.JPG") ||
            !_player_image.LoadFromFile("assets/enemy1.png") ||
            !_enemy_image.LoadFromFile("assets/enemy2.png") ||
            !_frite_image.LoadFromFile("assets/frite.png"))
    {
        _background_sprite = Sprite ();
        _player_sprite = Sprite();
        _enemy_sprite = Sprite();
        _frite_sprite = Sprite();
    }
    else
    {
        _background_sprite = Sprite(_background_image);
        _background_sprite.Resize(_w, _h);
        _background_sprite.SetPosition(0,0);

        _player_sprite = Sprite(_player_image);
        _enemy_sprite = Sprite(_enemy_image);
        _frite_sprite = Sprite(_frite_image);
    }
}

// -- ~Game_View --------------------------------
// Deletes the game view
// ----------------------------------------------
Game_View::~Game_View()
{
    if(_window != NULL)
    {
        delete _window;
    }
}

//=======================================
// Accesseurs en écriture
//=======================================
void Game_View::setModel(Game_Model * model)
{
    _model = model;
}

//=======================================
// Fonction de dessin
//=======================================
void Game_View::draw()
{
    ////Background////
    _window->Clear();
    _window->Draw(_background_sprite);
    //////////////////

    int x, y, w, h;
    //////Player//////
    _model->getPlayerSettings(x, y, w, h);
    _player_sprite.Resize(w, h);
    _player_sprite.SetPosition(x, y);
    _window->Draw(_player_sprite);
    //////////////////

    /////Enemies//////
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        _model->getEnemySettings(x, y, w, h);
        _enemy_sprite.Resize(w, h);
        _enemy_sprite.SetPosition(x, y);
        _window->Draw(_enemy_sprite);
        _window->Display();
    }
    //////////////////

    /////Tirs///////
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        for(int j=0; j < (_model->getEnemy(i))->getShotsSize(); j++)
        {
            (_model->getEnemy(i))->getShotSettings(x, y, w, h);
            _frite_sprite.Resize(w, h);
            _frite_sprite.SetPosition(x, y);
            _window->Draw(_frite_sprite);
            _window->Display();
        }
    }
    for (int k=0; k < (_model->getPlayer())->getShotsSize(); k++)
    {
        _model->getPlayer()->getShotSettings(x, y, w, h);
        _frite_sprite.Resize(w, h);
        _frite_sprite.SetPosition(x, y);
        _window->Draw(_frite_sprite);
        _window->Display();
    }
    ////////////////
    _window->Display();
}

//=======================================
// Traitement des evenements
// Retourne false si un evenement de fin est reçu
//=======================================
bool Game_View::treatEvents()
{
    bool result = false;
    if(_window->IsOpened())
    {
        result = true;
        Event event;
        while (_window->GetEvent(event))
        {
            if ((event.Type == Event::Closed) ||
                    ((event.Type == Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
            {
                _window->Close();
                result = false;
            }
        }
    }
    return result;
}


