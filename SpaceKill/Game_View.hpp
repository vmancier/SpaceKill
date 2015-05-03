/********************************************************************************************
 * Project: SpaceKill
 * File: Game_View.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef GAME_VIEW_HPP_INCLUDED
#define GAME_VIEW_HPP_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game_Model;

class Game_View
{
private:
    int _w, _h;

    sf::RenderWindow * _window;

    sf::Image _background_image;
    sf::Image _player_image;

    sf::Sprite _background_sprite;
    sf::Sprite _player_sprite;

    Game_Model * _model;

public:
    Game_View(int w, int h, int bpp);
    ~Game_View();

    void setModel(Game_Model * model);
    void draw();
    bool treatEvents();

};

#endif // GAME_VIEW_HPP_INCLUDED
