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
        system("cls");
        model->nextStep();
    }

    delete model;

    cout << "Hello world"<< endl;
    return 0;
}
