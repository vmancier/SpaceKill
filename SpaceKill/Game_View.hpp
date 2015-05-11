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
    sf::Image _enemy1_image;
    sf::Image _enemy2_image;
    sf::Image _enemy3_image;
    sf::Image _enemy4_image;
    sf::Image _enemy5_image;
    sf::Image _enemy6_image;
    sf::Image _enemy7_image;
    sf::Image _enemy8_image;
    sf::Image _shot1_image;

    sf::Sprite _background_sprite;
    sf::Sprite _player_sprite;
    sf::Sprite _enemy1_sprite;
    sf::Sprite _enemy2_sprite;
    sf::Sprite _enemy3_sprite;
    sf::Sprite _enemy4_sprite;
    sf::Sprite _enemy5_sprite;
    sf::Sprite _enemy6_sprite;
    sf::Sprite _enemy7_sprite;
    sf::Sprite _enemy8_sprite;
    sf::Sprite _shot1_sprite;

    Game_Model *_model;

public:
    Game_View(int w, int h, int bpp);
    ~Game_View();

    void draw();
    void drawEnemies();
    void drawEnemiesBis(sf::Sprite);
    bool treatEvents(sf::Clock &clock);
    void setModel(Game_Model *model);

};

#endif // GAME_VIEW_HPP_INCLUDED
