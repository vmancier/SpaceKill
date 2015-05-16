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
    int _y_background;

    sf::RenderWindow * _window;

    sf::Image _background_image;
    sf::Image _headband_image;
    sf::Image _healthbar_image;
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
    sf::Image _shot2_image;
    sf::Image _shot3_image;

    sf::Sprite _background_sprite;
    sf::Sprite _headband_sprite;
    sf::Sprite _healthbar_sprite;
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
    sf::Sprite _shot2_sprite;
    sf::Sprite _shot3_sprite;

    sf::Font _score_font;

    Game_Model *_model;

public:
    Game_View(int w, int h, int bpp);
    ~Game_View();

    void draw();
    void drawBackground();
    void drawSprite(int x, int y, int w, int h, sf::Sprite mySprite);
    void drawPlayerShots();
    void drawPlayerShotsSprites1(sf::Sprite);
    void drawPlayerShotsSprites2(sf::Sprite, sf::Sprite);
    void drawPlayerShotsSprites3(sf::Sprite, sf::Sprite);
    void drawEnemiesShots();
    void drawPlayer();
    void drawEnemies();
    void drawEnemiesSprites(sf::Sprite);
    void drawHeadBand();
    void drawLife();
    void drawHealth();
    void drawHealthLevel(int x);
    void drawScore();

    bool treatEvents(float timedelta);
    void setModel(Game_Model *model);
};

#endif // GAME_VIEW_HPP_INCLUDED
