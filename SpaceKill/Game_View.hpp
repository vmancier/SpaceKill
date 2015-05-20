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
    sf::Image _button1_image;
    sf::Image _button11_image;
    sf::Image _button2_image;
    sf::Image _button21_image;
    sf::Image _headband_image;
    sf::Image _healthbar_image;
    sf::Image _player_image;
    sf::Image _player1_image;
    sf::Image _player2_image;
    sf::Image _enemy0_image;
    sf::Image _enemy1_image;
    sf::Image _enemy2_image;
    sf::Image _enemy3_image;
    sf::Image _enemy4_image;
    sf::Image _enemy5_image;
    sf::Image _enemy6_image;
    sf::Image _enemy7_image;
    sf::Image _shot0_image;
    sf::Image _shot1_image;
    sf::Image _shot2_image;

    sf::Sprite _background_sprite;
    sf::Sprite _button1_sprite;
    sf::Sprite _button11_sprite;
    sf::Sprite _button2_sprite;
    sf::Sprite _button21_sprite;
    sf::Sprite _headband_sprite;
    sf::Sprite _healthbar_sprite;
    sf::Sprite _player_sprite;
    sf::Sprite _player1_sprite;
    sf::Sprite _player2_sprite;
    sf::Sprite _enemy0_sprite;
    sf::Sprite _enemy1_sprite;
    sf::Sprite _enemy2_sprite;
    sf::Sprite _enemy3_sprite;
    sf::Sprite _enemy4_sprite;
    sf::Sprite _enemy5_sprite;
    sf::Sprite _enemy6_sprite;
    sf::Sprite _enemy7_sprite;
    sf::Sprite _shot0_sprite;
    sf::Sprite _shot1_sprite;
    sf::Sprite _shot2_sprite;

    sf::Font _minimal_font;

    sf::String _score_string;
    sf::String _title_string;

    Game_Model *_model;

public:
    Game_View(int w, int h, int bpp);
    ~Game_View();

    void drawSprite(int x, int y, int w, int h, sf::Sprite mySprite);

    /** Introduction **/
    void drawIntro(sf::Clock clock);
    void drawBackground();
    void drawAnimation(float t);
    void drawTitle();


    /** Menu **/
    void drawMenu();
    void drawButtons();

    /** Game **/
    void drawGame();
    void drawPlayerShots();
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
    bool treatMenuEvents();
    void setModel(Game_Model *model);
};

#endif // GAME_VIEW_HPP_INCLUDED
