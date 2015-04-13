#include "Game_Model.hpp"
#include "Entities.hpp"
#include "Game_View.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

using namespace sf;

int main()
{
    srand(time(NULL));
    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    //RenderWindow *_window = new RenderWindow(VideoMode(800, 600, 32), "SpaceKill", Style::Close);
    //Game_View *view = new Game_View(VIEW_WIDTH, VIEW_HEIGHT, VIEW_BPP);
    //view->draw();
    //view->setModel(model);
    while(model->Play())
    {
        model->nextStep();
        system("cls");
    }

    delete model;
    //delete view;
    return 0;
}
