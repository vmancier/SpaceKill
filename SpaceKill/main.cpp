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

//#include <SFML/System.hpp>

#include <cstdlib>
#include <iostream>

using namespace std;

using namespace sf;

int main()
{
    srand(time(NULL));
    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    while(model->Play())
    {
        cout<< endl << "----------DEPLACEMENT SUIVANT----------" << endl <<endl ;
        model->nextStep();
    }

    delete model;
    return 0;
}
