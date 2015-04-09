#include <iostream>
#include "Game_Model.hpp"
#include "Entities.hpp"
#include <cstdlib>

using namespace std;

int main()
{
    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    while(model->Play())
    {
        model->nextStep();
        system("cls");
    }

    delete model;
    return 0;
}
