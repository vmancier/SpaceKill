#include <iostream>
#include "Game_Model.hpp"
#include "Entities.hpp"
#include <cstdlib>

using namespace std;

int main()
{
    int nb=0;
    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    while(model->Play())
    {
        model->nextStep();
        nb++;
        cout <<nb <<" ennemis generes aleatoirement non delete"<<endl;
        //system("cls");
    }

    delete model;

    cout << "Hello world"<< endl;
    return 0;
}
