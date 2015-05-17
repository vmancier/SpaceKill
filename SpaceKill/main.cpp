/********************************************************************************************
 * Project: SpaceKill
 * File: main.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "Game_Model.hpp"
#include "Entities.hpp"
#include "Game_View.hpp"

#include <cstdlib>
#include <iostream>
//#include <windows.h>
//#include <unistd.h>

using namespace std;

using namespace sf;

int main()
{
    srand(time(NULL));
    Clock clock;
    float timedelta = 0.0;

    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    Game_View *view = new Game_View(VIEW_WIDTH,VIEW_HEIGHT, VIEW_BPP);
    view->setModel(model);

    while(timedelta < 5.0)
    {
        view->drawIntro();
        timedelta = clock.GetElapsedTime();
    }

    while(view->treatEvents(timedelta))
    {
        clock.Reset();

        view->drawGame();
        //cout<< endl << "----------DEPLACEMENT SUIVANT----------" << endl <<endl ;

        model->nextStep(timedelta);
        timedelta = clock.GetElapsedTime();
    }

    delete view;
    delete model;
    return 0;
}
















