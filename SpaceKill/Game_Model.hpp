#ifndef GAME_MODEL_HPP_INCLUDED
#define GAME_MODEL_HPP_INCLUDED

class Game_Model
{
private:
    int _w, _h;
    //Ball * _ball;
public:
    Game_Model();
    Game_Model(int w, int h);
    ~Game_Model();

    void nextStep();

    void getBallPos(int &x, int &y) const;
    void getBallSize(int &w, int &h) const;
};

#endif // GAME_MODEL_HPP_INCLUDED
