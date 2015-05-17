/********************************************************************************************
 * Project: SpaceKill
 * File: Score.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include <string>
#include "string.h"
#include "Score.hpp"

using namespace std;

Score::Score()
{
    m_score = 1000;
}

void Score::scoreCalculation(int value)
{
    m_score +=value;
}

/*string Score::toString() const {
    return "(" + to_string(m_score) + ",";
}*/
