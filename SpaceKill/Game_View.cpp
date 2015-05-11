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
            !_shot1_image.LoadFromFile("assets/shot1.png") ||
            !_shot2_image.LoadFromFile("assets/shot2.png") ||
            !_shot3_image.LoadFromFile("assets/shot3.png"))
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
        _shot2_sprite = Sprite();
        _shot3_sprite = Sprite();
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
        _shot2_sprite = Sprite(_shot2_image);
        _shot3_sprite = Sprite(_shot3_image);
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
    _window->Clear();
    _window->Draw(_background_sprite);

    Game_View::drawPlayerShots();
    Game_View::drawEnemiesShots();
    Game_View::drawPlayer();
    Game_View::drawEnemies();

    _window->Display();
}

void Game_View::drawSprite(int x, int y, int w, int h, Sprite mySprite)
{
    mySprite.Resize(w, h);
    mySprite.SetPosition(x, y);
    _window->Draw(mySprite);
}

void Game_View::drawPlayerShots()
{
    int style = _model->getLevelNumber();
    switch(style)
    {
    case 1:
        Game_View::drawPlayerShotsSprites1(_shot1_sprite);
        break;
    case 2:
        Game_View::drawPlayerShotsSprites1(_shot1_sprite);
        break;
    case 3:
        Game_View::drawPlayerShotsSprites2(_shot1_sprite, _shot2_sprite);
        break;
    case 4:
        Game_View::drawPlayerShotsSprites2(_shot1_sprite, _shot2_sprite);
        break;
    case 5:
        Game_View::drawPlayerShotsSprites3(_shot2_sprite, _shot3_sprite);
        break;
    case 6:
        Game_View::drawPlayerShotsSprites3(_shot2_sprite, _shot3_sprite);
        break;
    case 7:
        Game_View::drawPlayerShotsSprites3(_shot2_sprite, _shot3_sprite);
        break;
    case 8:
        Game_View::drawPlayerShotsSprites3(_shot2_sprite, _shot3_sprite);
        break;
    }
}

void Game_View::drawPlayerShotsSprites1(sf::Sprite myPlayerShotSprite)
{
    int x, y, w, h;
    for (int i=0; i < (_model->getPlayer())->getShotsSize(); i++)
    {
        (_model->getPlayer())->getShotSettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, w, h, myPlayerShotSprite);
    }
}

void Game_View::drawPlayerShotsSprites2(sf::Sprite myPlayerShotSprite1, sf::Sprite myPlayerShotSprite2)
{
    int x, y, w, h;
    for (int i=0; i < (_model->getPlayer())->getShotsSize(); i++)
    {
        (_model->getPlayer())->getShotSettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, w, h, myPlayerShotSprite1);
        Game_View::drawSprite((x+PLAYER_WIDTH/2), (y+PLAYER_HEIGHT/4), w, h, myPlayerShotSprite2);
        Game_View::drawSprite((x-PLAYER_WIDTH/2), (y+PLAYER_HEIGHT/4), w, h, myPlayerShotSprite2);
    }
}

void Game_View::drawPlayerShotsSprites3(sf::Sprite myPlayerShotSprite1, sf::Sprite myPlayerShotSprite2)
{
    int x, y, w, h;
    for (int i=0; i < (_model->getPlayer())->getShotsSize(); i++)
    {
        (_model->getPlayer())->getShotSettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, w, h, myPlayerShotSprite1);
        for (int j=0; j<(_model->getPlayer())->getShotsSize(); j++)
        {
            Game_View::drawSprite(x+PLAYER_WIDTH+j, y-j, w, h, myPlayerShotSprite1);
            Game_View::drawSprite(x-PLAYER_WIDTH-j, y-j, w, h, myPlayerShotSprite1);
        }

        Game_View::drawSprite((x+PLAYER_WIDTH/2), (y+PLAYER_HEIGHT/4), w, h, myPlayerShotSprite2);
        Game_View::drawSprite((x-PLAYER_WIDTH/2), (y+PLAYER_HEIGHT/4), w, h, myPlayerShotSprite2);
    }
}

void Game_View::drawEnemiesShots()
{
    int x, y, w, h;
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        for(int j=0; j < (_model->getEnemy(i))->getShotsSize(); j++)
        {
            (_model->getEnemy(i))->getShotSettings(x, y, w, h, j);
            Game_View::drawSprite(x, y, w, h, _shot1_sprite);
        }
    }
}

void Game_View::drawPlayer()
{
    int x, y, w, h;
    _model->getPlayerSettings(x, y, w, h);
    Game_View::drawSprite(x, y, w, h, _player_sprite);
}

// -- drawEnemies -------------------------------
// Draws all the enemies
// ----------------------------------------------
void Game_View::drawEnemies()
{
    int style = _model->getLevelNumber();
    switch(style)
    {
    case 1:
        Game_View::drawEnemiesSprites(_enemy1_sprite);
        break;
    case 2:
        Game_View::drawEnemiesSprites(_enemy2_sprite);
        break;
    case 3:
        Game_View::drawEnemiesSprites(_enemy3_sprite);
        break;
    case 4:
        Game_View::drawEnemiesSprites(_enemy4_sprite);
        break;
    case 5:
        Game_View::drawEnemiesSprites(_enemy5_sprite);
        break;
    case 6:
        Game_View::drawEnemiesSprites(_enemy6_sprite);
        break;
    case 7:
        Game_View::drawEnemiesSprites(_enemy7_sprite);
        break;
    case 8:
        Game_View::drawEnemiesSprites(_enemy8_sprite);
        break;
    }
}

void Game_View::drawEnemiesSprites(Sprite myEnemySprite)
{
    int x, y, w, h;
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        _model->getEnemySettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, w, h, myEnemySprite);
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
        (_model->getPlayer())->moveP(event, timedelta);
        _model->moveEnemies(timedelta);
        _model->moveShots(timedelta);

    }
    clock.Reset();
    return result;
}

// -- setModel ----------------------------------
// Sets the model
// ----------------------------------------------
void Game_View::setModel(Game_Model *model)
{
    _model = model;
}
