#include <iostream>
#include "Game_View.hpp"
#include "Game_Model.hpp"
#include "Entities.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace std;

using namespace sf;

// -- Game_View ---------------------------------
// Builds the game view
// * in-parameters :
// - w, int : width of the window
// - h, int : height of the window
// - bb, int : number of bits by pixel
// ----------------------------------------------
Game_View::Game_View(int w, int h, int bpp): _w(w), _h(h)
{
    _window = new RenderWindow(sf::VideoMode(w, h, bpp), "SpaceKill", sf::Style::Close);

    if (!_background_image.LoadFromFile("assets/background.gif"))
    {
        _background_sprite = Sprite();
    }
    else
    {
        _background_sprite = Sprite(_background_image);
        _background_sprite.Resize(_w, _h);
        _background_sprite.SetPosition(0,0);
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
   /* _window->Draw(_background_sprite);

    int x_ball, y_ball;
     int w_ball, h_ball;
     _model->getBallPos(x_ball, y_ball);
     _model->getBallSize(w_ball, h_ball);

     _ball_sprite.Resize(w_ball, h_ball);
     _ball_sprite.SetPosition(x_ball, y_ball);
     _window->Draw(_ball_sprite);
*/
    _window->Display();
}


