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
            !_player_image.LoadFromFile("assets/player0.png") ||
            !_enemy1_image.LoadFromFile("assets/enemy1.png") ||
            !_enemy2_image.LoadFromFile("assets/enemy2.png") ||
            !_enemy3_image.LoadFromFile("assets/enemy3.png") ||
            !_enemy4_image.LoadFromFile("assets/enemy4.png") ||
            !_enemy5_image.LoadFromFile("assets/enemy5.png") ||
            !_enemy6_image.LoadFromFile("assets/enemy6.png") ||
            !_enemy7_image.LoadFromFile("assets/enemy7.png") ||
            !_enemy8_image.LoadFromFile("assets/enemy8.png") ||
            !_shot1_image.LoadFromFile("assets/shot1.png"))
    {
        _background_sprite = Sprite ();
        _player_sprite = Sprite();
        _enemy1_sprite = Sprite();
        _enemy2_sprite = Sprite();
        _enemy3_sprite = Sprite();
        _enemy4_sprite = Sprite();
        _enemy5_sprite = Sprite();
        _enemy6_sprite = Sprite();
        _enemy7_sprite = Sprite();
        _enemy8_sprite = Sprite();
        _shot1_sprite = Sprite();
    }
    else
    {
        _background_sprite = Sprite(_background_image);
        _background_sprite.Resize(_w, _h);
        _background_sprite.SetPosition(0,0);

        _player_sprite = Sprite(_player_image);
        _enemy1_sprite = Sprite(_enemy1_image);
        _enemy2_sprite = Sprite(_enemy2_image);
        _enemy3_sprite = Sprite(_enemy3_image);
        _enemy4_sprite = Sprite(_enemy4_image);
        _enemy5_sprite = Sprite(_enemy5_image);
        _enemy6_sprite = Sprite(_enemy6_image);
        _enemy7_sprite = Sprite(_enemy7_image);
        _enemy8_sprite = Sprite(_enemy8_image);
        _shot1_sprite = Sprite(_shot1_image);
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

// -- draw --------------------------------------
// Draws all the necessary elements for the game
// ----------------------------------------------
void Game_View::draw()
{
    ////Background////
    _window->Clear();
    _window->Draw(_background_sprite);


    //////Player//////
    int x, y, w, h;
    _model->getPlayerSettings(x, y, w, h);
    _player_sprite.Resize(w, h);
    _player_sprite.SetPosition(x, y);
    _window->Draw(_player_sprite);

    /////Enemies//////
    Game_View::drawEnemies();

    /////Shots///////
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        for(int j=0; j < (_model->getEnemy(i))->getShotsSize(); j++)
        {
            (_model->getEnemy(i))->getShotSettings(x, y, w, h);
            _shot1_sprite.Resize(w, h);
            _shot1_sprite.SetPosition(x, y);
            _window->Draw(_shot1_sprite);
            //_window->Display();
        }
    }

    for (int k=0; k < (_model->getPlayer())->getShotsSize(); k++)
    {
        _model->getPlayer()->getShotSettings(x, y, w, h);
        _shot1_sprite.Resize(w, h);
        _shot1_sprite.SetPosition(x, y);
        _window->Draw(_shot1_sprite);
        //_window->Display();
    }

    ////////////////
    _window->Display();
}

// -- drawEnemies -------------------------------
// Draws all the enemies
// ----------------------------------------------
void Game_View::drawEnemies()
{
    int x, y, w, h;
    int style = _model->getLevelNumber();
    switch(style)
    {
    case 1:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h, i);
            _enemy1_sprite.Resize(w, h);
            _enemy1_sprite.SetPosition(x, y);
            _window->Draw(_enemy1_sprite);
            //_window->Display();
        }
        break;
    case 2:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy2_sprite.Resize(w, h);
            _enemy2_sprite.SetPosition(x, y);
            _window->Draw(_enemy2_sprite);
            //_window->Display();
        }
        break;
    case 3:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy3_sprite.Resize(w, h);
            _enemy3_sprite.SetPosition(x, y);
            _window->Draw(_enemy3_sprite);
            //_window->Display();
        }
        break;
    case 4:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy4_sprite.Resize(w, h);
            _enemy4_sprite.SetPosition(x, y);
            _window->Draw(_enemy4_sprite);
            //_window->Display();
        }
        break;
    case 5:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy5_sprite.Resize(w, h);
            _enemy5_sprite.SetPosition(x, y);
            _window->Draw(_enemy5_sprite);
            //_window->Display();
        }
        break;
    case 6:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy6_sprite.Resize(w, h);
            _enemy6_sprite.SetPosition(x, y);
            _window->Draw(_enemy6_sprite);
            //_window->Display();
        }
        break;
    case 7:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy7_sprite.Resize(w, h);
            _enemy7_sprite.SetPosition(x, y);
            _window->Draw(_enemy7_sprite);
            //_window->Display();
        }
        break;
    case 8:
        for(int i=0; i < _model->getEnemiesSize(); i++)
        {
            _model->getEnemySettings(x, y, w, h,i);
            _enemy8_sprite.Resize(w, h);
            _enemy8_sprite.SetPosition(x, y);
            _window->Draw(_enemy8_sprite);
            //_window->Display();
        }
        break;
    }
}

// -- treatEvents -------------------------------
// Treat the game's events
// ----------------------------------------------
bool Game_View::treatEvents(Clock &clock)
{
    bool result = false;

    float timedelta = clock.GetElapsedTime();

    if(_window->IsOpened())
    {
        result = true;
        Event event;
        _window->GetEvent(event);

        if ((event.Type == Event::Closed) ||
                ((event.Type == Event::KeyPressed) &&
                 (event.Key.Code == sf::Key::Escape)))
        {
            _window->Close();
            result = false;
        }

        // Deplacement du joueur
        (_model->getPlayer())->moveP(event, timedelta);

        // Deplacement des enemmis
        _model->moveEnemies(timedelta);

    }
    //Reset ton horloge à chaque frame
    clock.Reset();
    return result;
}

// -- setModel ----------------------------------
// Sets the model
// ----------------------------------------------
void Game_View::setModel(Game_Model * model)
{
    _model = model;
}
