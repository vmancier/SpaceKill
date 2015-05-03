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

    if (!_background_image.LoadFromFile("assets/enemy0.png") ||
        !_player_image.LoadFromFile("assets/enemy1.png"))
    {
        _background_sprite = Sprite ();
        _player_sprite = Sprite();
    }
    else
    {

        _background_sprite = Sprite (_background_image);
        _background_sprite.Resize(_w, _h);
        _background_sprite.SetPosition(0,0);

        _player_sprite = Sprite(_player_image);
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
    _window->Clear();
    _window->Draw(_background_sprite);

    int x, y, w, h;

    _model->getPlayerSettings(x, y, w, h);

    //cout <<x<<" "<<y<<" "<<w<<" "<<h;

    _player_sprite.Resize(w, h);
    _player_sprite.SetPosition(x, y);

    _window->Draw(_player_sprite);

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


