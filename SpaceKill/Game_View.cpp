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
#include <sstream>
#include <string>

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
    _window->UseVerticalSync(false);
    _window->SetFramerateLimit(60);

    if (!_background_image.LoadFromFile("assets/background.JPG") ||
            !_button1_image.LoadFromFile("assets/button1.png") ||
            !_button2_image.LoadFromFile("assets/button2.png") ||
            !_headband_image.LoadFromFile("assets/headband.png") ||
            !_healthbar_image.LoadFromFile("assets/healthbar.png") ||
            !_player_image.LoadFromFile("assets/player.png") ||
            !_player1_image.LoadFromFile("assets/player1.png") ||
            !_player2_image.LoadFromFile("assets/player2.png") ||
            !_enemy0_image.LoadFromFile("assets/enemy0.png") ||
            !_enemy1_image.LoadFromFile("assets/enemy1.png") ||
            !_enemy2_image.LoadFromFile("assets/enemy2.png") ||
            !_enemy3_image.LoadFromFile("assets/enemy3.png") ||
            !_enemy4_image.LoadFromFile("assets/enemy4.png") ||
            !_enemy5_image.LoadFromFile("assets/enemy5.png") ||
            !_enemy6_image.LoadFromFile("assets/enemy6.png") ||
            !_enemy7_image.LoadFromFile("assets/enemy7.png") ||
            !_shot0_image.LoadFromFile("assets/shot0.png") ||
            !_shot1_image.LoadFromFile("assets/shot1.png") ||
            !_shot2_image.LoadFromFile("assets/shot2.png") ||
            !_title_image.LoadFromFile("assets/title.png") ||
            !_minimal_font.LoadFromFile("assets/minimal.ttf") ||
            !_transition_image.LoadFromFile("assets/transition.png") ||
            !_gameover_image.LoadFromFile("assets/gameover.png") ||
            !_music.OpenFromFile("assets/music.ogg"))
    {
        _background_sprite = Sprite();
        _button1_sprite = Sprite();
        _button2_sprite = Sprite();
        _headband_sprite = Sprite();
        _healthbar_sprite = Sprite();
        _player_sprite = Sprite();
        _player1_sprite = Sprite();
        _player2_sprite = Sprite();
        _enemy0_sprite = Sprite();
        _enemy1_sprite = Sprite();
        _enemy2_sprite = Sprite();
        _enemy3_sprite = Sprite();
        _enemy4_sprite = Sprite();
        _enemy5_sprite = Sprite();
        _enemy6_sprite = Sprite();
        _enemy7_sprite = Sprite();
        _shot0_sprite = Sprite();
        _shot1_sprite = Sprite();
        _shot2_sprite = Sprite();
        _title_sprite = Sprite();
        _minimal_font = Font();
        _transition_sprite = Sprite();
        _gameover_sprite = Sprite();
    }
    else
    {
        _y_background = 0;
        _background_sprite = Sprite(_background_image);
        _background_sprite.SetPosition(0,_y_background);

        _button1_sprite = Sprite(_button1_image);
        _button2_sprite = Sprite(_button2_image);

        _headband_sprite = Sprite(_headband_image);
        _healthbar_sprite = Sprite(_healthbar_image);

        _player_sprite = Sprite(_player_image);
        _player1_sprite = Sprite(_player1_image);
        _player2_sprite = Sprite(_player2_image);
        _enemy0_sprite = Sprite(_enemy0_image);
        _enemy1_sprite = Sprite(_enemy1_image);
        _enemy2_sprite = Sprite(_enemy2_image);
        _enemy3_sprite = Sprite(_enemy3_image);
        _enemy4_sprite = Sprite(_enemy4_image);
        _enemy5_sprite = Sprite(_enemy5_image);
        _enemy6_sprite = Sprite(_enemy6_image);
        _enemy7_sprite = Sprite(_enemy7_image);
        _shot0_sprite = Sprite(_shot0_image);
        _shot1_sprite = Sprite(_shot1_image);
        _shot2_sprite = Sprite(_shot2_image);
        _title_sprite = Sprite(_title_image);
        _transition_sprite = Sprite(_transition_image);
        _gameover_sprite = Sprite(_gameover_image);
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

void Game_View::drawIntro(Clock clock)
{
    float timedelta;
    float t = 0.0;
    while(t < 500.0)
    {
        _window->Clear();
        drawBackground();
        drawAnimation(t);
        drawTitle();
        _window->Display();
        timedelta = clock.GetElapsedTime();
        t+=timedelta;
    }

}

void Game_View::drawBackground()
{
    drawSprite(0,_y_background, MODEL_WIDTH, MODEL_HEIGHT,_background_sprite);
    drawSprite(0,-MODEL_HEIGHT+_y_background, MODEL_WIDTH, MODEL_HEIGHT,_background_sprite);
    _y_background += 1 ;
    if (_y_background >= MODEL_HEIGHT)
    {
        _y_background =0;
    }
}

void Game_View::drawAnimation(float t)
{
    drawSprite(100+t, 540-t, 150, 150, _player1_sprite);
    _player1_sprite.SetRotation(-50);
    drawSprite(VIEW_WIDTH-200-t, 650-t, 150, 150, _player2_sprite);
    _player2_sprite.SetRotation(50);

}

void Game_View::drawTitle()
{
    drawSprite(0, 0, 440, 150, _title_sprite);
}

void Game_View::drawMenu()
{
    _window->Clear();
    drawBackground();
    drawTitle();
    drawButtons();
    _window->Display();
}

void Game_View::drawButtons()
{
    drawSprite(VIEW_WIDTH/2-(_button1_sprite.GetSize().x)/2, VIEW_HEIGHT/2, _button1_sprite.GetSize().x, _button1_sprite.GetSize().y, _button1_sprite);
    _button1_sprite.SetPosition(VIEW_WIDTH/2-(_button1_sprite.GetSize().x)/2, VIEW_HEIGHT/2);
    drawSprite(VIEW_WIDTH/2-(_button2_sprite.GetSize().x)/2, VIEW_HEIGHT-_button1_sprite.GetSize().x, _button2_sprite.GetSize().x, _button2_sprite.GetSize().y, _button2_sprite);
    _button2_sprite.SetPosition(VIEW_WIDTH/2-(_button2_sprite.GetSize().x)/2, VIEW_HEIGHT-_button1_sprite.GetSize().x);
}
// -- drawGame ----------------------------------
// Draws all the necessary elements for the game
// ----------------------------------------------
void Game_View::drawGame()
{
    _window->Clear();
    drawBackground();

    drawPlayerShots();
    drawEnemiesShots();
    drawPlayer();
    drawEnemies();
    drawHeadBand();

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
    sf::Sprite myPlayerShotSprite;
    int x, y, w, h;
    int style;
    for (int i=0; i < (_model->getPlayer())->getShotsSize(); i++)
    {
        style = _model->getPlayer()->getShot(i)->getStyle();
        _model->getPlayer()->getShotSettings(x, y, w, h, i);
        if(style==0 ||style==1)
        {
            myPlayerShotSprite =_shot0_sprite;
        }
        else if (style==2 || style==3)
        {
            myPlayerShotSprite =_shot1_sprite;
        }
        else
        {
            myPlayerShotSprite =_shot2_sprite;
        }
        int xSpeed =_model->getPlayer()->getShot(i)->getXSpeed();
        if(xSpeed>0)
        {
            myPlayerShotSprite.SetRotation(-45);
        }
        else if (xSpeed<0)
        {
            myPlayerShotSprite.SetRotation(45);
        }
        drawSprite(x, y, w, h, myPlayerShotSprite);
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
    drawSprite(x, y, w, h, _player_sprite);
}

// -- drawEnemies -------------------------------
// Draws all the enemies
// ----------------------------------------------
void Game_View::drawEnemies()
{
    int style = _model->getLevelNumber()%8;
    switch(style)
    {
    case 0:
        Game_View::drawEnemiesSprites(_enemy0_sprite);
        break;
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
    }
}

void Game_View::drawEnemiesSprites(Sprite myEnemySprite)
{
    int x, y, w, h;
    for (int i=0; i < _model->getEnemiesSize(); i++)
    {
        _model->getEnemySettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, w, h, myEnemySprite);
    }
}

void Game_View::drawHeadBand()
{
    drawSprite(0, 0, 440, 20, _headband_sprite);
    drawLife();
    drawHealth();
    drawScore();
}

void Game_View::drawLife()  //nombre de vies
{
    int lifeNumber = (_model->getPlayer())->getLife();
    switch (lifeNumber)
    {

    case 1:
        drawSprite(2, 0, 19, 19, _player_sprite);
        break;
    case 2:
        drawSprite(2, 0, 19, 19, _player_sprite);
        drawSprite(27, 0, 19, 19, _player_sprite);
        break;
    case 3:
        drawSprite(2, 0, 19, 19, _player_sprite);
        drawSprite(27, 0, 19, 19, _player_sprite);
        drawSprite(52, 0, 19, 19, _player_sprite);
        break;
    }
}

void Game_View::drawHealth()    //niveau de la vie en cours
{
    int lifeLevel = (_model->getPlayer()->getCurrentHealth()/_model->getPlayer()->getHealthMax())*100;
    switch (lifeLevel)
    {
    case 100:
        drawHealthLevel(200);
        break;
    case 90:
        drawHealthLevel(179);
        break;
    case 80:
        drawHealthLevel(159);
        break;
    case 70:
        drawHealthLevel(139);
        break;
    case 60:
        drawHealthLevel(119);
        break;
    case 50:
        drawHealthLevel(99);
        break;
    case 40:
        drawHealthLevel(79);
        break;
    case 30:
        drawHealthLevel(59);
        break;
    case 20:
        drawHealthLevel(39);
        break;
    case 10:
        drawHealthLevel(19);
        break;
    }
}

void Game_View::drawHealthLevel(int x)
{
    _healthbar_sprite.SetSubRect(sf::IntRect(0, 0, x, 10));
    drawSprite(100, 5, x, 10, _healthbar_sprite);
}

template <typename T>
std::string to_string(T value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void Game_View::drawScore()
{
    std::string str = "Score : ";
    str += to_string(_model->getScore());

    _score_string.SetText(str);
    _score_string.SetFont(_minimal_font);
    _score_string.SetSize(20);
    _score_string.SetPosition(320, -5);
    _score_string.SetColor(sf::Color(0, 0, 0));
    _window->Draw(_score_string);
}

// -- treatEvents -------------------------------
// Treat the game's events
// ----------------------------------------------
bool Game_View::treatEvents(float timedelta)
{
    bool result = false;
    if(_window->IsOpened())
    {
        result = true;
        Event event;
        _window->GetEvent(event);

        const sf::Input& input = _window->GetInput();
        bool EscapeKeyDown = input.IsKeyDown(sf::Key::Escape);
        bool LeftKeyDown = input.IsKeyDown(sf::Key::Left);
        bool RightKeyDown = input.IsKeyDown(sf::Key::Right);
        bool UpKeyDown = input.IsKeyDown(sf::Key::Up);
        bool DownKeyDown = input.IsKeyDown(sf::Key::Down);
        bool ZKeyDown = input.IsKeyDown(sf::Key::Z);
        bool QKeyDown = input.IsKeyDown(sf::Key::Q);
        bool SKeyDown = input.IsKeyDown(sf::Key::S);
        bool DKeyDown = input.IsKeyDown(sf::Key::D);

        if (EscapeKeyDown)
        {
            _window->Close();
            result = false;
        }
        (_model->getPlayer())->moveP(LeftKeyDown, QKeyDown, RightKeyDown, DKeyDown, UpKeyDown, ZKeyDown, DownKeyDown, SKeyDown, timedelta);
    }
    return result;
}

bool Game_View::treatMenuEvents()
{
    bool runMenu = true;
    sf::Event _menu_event;
    _window->GetEvent(_menu_event);

    const sf::Input &menuInput = _window->GetInput();
    bool LeftMouseKeyDown = menuInput.IsMouseButtonDown(sf::Mouse::Left);
    bool EscapeKeyDown = menuInput.IsKeyDown(sf::Key::Escape);

    if ((LeftMouseKeyDown) && (_menu_event.MouseButton.X > _button1_sprite.GetPosition().x) && (_menu_event.MouseButton.X < (_button1_sprite.GetSize().x)+(_button1_sprite.GetPosition().x)) && (_menu_event.MouseButton.Y > _button1_sprite.GetPosition().y) && (_menu_event.MouseButton.Y < (_button1_sprite.GetSize().y)+(_button1_sprite.GetPosition().y)))
//    if ((&menuInput.GetMouseX > _button1_sprite.GetPosition().x) && (&menuInput.GetMouseX < (_button1_sprite.GetSize().x)+(_button1_sprite.GetPosition().x)) && (&menuInput.GetMouseY > _button1_sprite.GetPosition().y) && (&menuInput.GetMouseY < (_button1_sprite.GetSize().y)+(_button1_sprite.GetPosition().y)))
    {
        runMenu = false;
    }
    if ((LeftMouseKeyDown) && (_menu_event.MouseButton.X > _button2_sprite.GetPosition().x) && (_menu_event.MouseButton.X < (_button2_sprite.GetSize().x)+(_button2_sprite.GetPosition().x)) && (_menu_event.MouseButton.Y > _button2_sprite.GetPosition().y) && (_menu_event.MouseButton.Y < (_button2_sprite.GetSize().y)+(_button2_sprite.GetPosition().y)))
    {
        _window->Close();
    }
    if (EscapeKeyDown)
    {
        _window->Close();
    }
    return runMenu;
}

// -- setModel ----------------------------------
// Sets the model
// ----------------------------------------------
void Game_View::setModel(Game_Model *model)
{
    _model = model;
}

void Game_View::playMusic(bool loop)
{
    if(loop)
    {
        _music.SetLoop(true);
    }
    _music.SetVolume(10.0);
    _music.Play();
}

void Game_View::drawTransition(sf::Clock m_clock)
{
    bool levelchange = _model->getLevelChange();
    if(levelchange)
    {
        _model->setLevelChange(false);
        float time = 0.0;
        float duration = 50.0;
        float timetogo = duration;
        while(timetogo > 0.0)
        {
            time = m_clock.GetElapsedTime();
            drawSprite(0, 0, 440, 720, _transition_sprite);
            _window->Display();
            timetogo -= time;
        }
    }
}

void Game_View::drawGameOver()
{
    bool dead = _model->getPlayer()->die();
    if(dead)
    {
        //float time = 0.0;
        //float duration = 50.0;
        //float timetogo = duration;
        while(true)//timetogo > 0.0)
        {
            //time = m_clock.GetElapsedTime();
            drawSprite(0, 0, 440, 720, _gameover_sprite);
            _window->Display();
            //timetogo -= time;
        }
    }
}
