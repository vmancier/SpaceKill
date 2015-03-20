#include <iostream>
#include "Game_View.hpp"
#include "Game_Model.hpp"
#include "Entities.hpp"

using namespace std;
/*
using namespace sf;

//=======================================
// Constructeur
//=======================================
Game_View::Game_View(int w, int h, int bpp): _w(w), _h(h)
{
    _window = new RenderWindow(sf::VideoMode(w, h, bpp), "SpaceKill", sf::Style::Close);

    if (!_background_image.LoadFromFile("background.png"))
        //!_ball_image.LoadFromFile("ball.png"))
    {
        _background_sprite = Sprite ();
        //_ball_sprite = Sprite();
    }
    else
    {
        _background_sprite = Sprite (_background_image);
        _background_sprite.Resize(_w, _h);
        _background_sprite.SetPosition(0,0);

        _ball_sprite = Sprite(_ball_image);
    }
}

//=======================================
// Destructeur
//=======================================
Game_View::~Game_View()
{
    if(_window!= NULL)
        delete _window;
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

    int x_ball, y_ball;
     int w_ball, h_ball;
     _model->getBallPos(x_ball, y_ball);
     _model->getBallSize(w_ball, h_ball);

     _ball_sprite.Resize(w_ball, h_ball);
     _ball_sprite.SetPosition(x_ball, y_ball);
     _window->Draw(_ball_sprite);

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
*/
