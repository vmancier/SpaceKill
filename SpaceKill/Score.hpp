/********************************************************************************************
 * Project: SpaceKill
 * File: Score.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED

class Score
{

private:
    int m_score;
public:
    Score();    //constructeur par défaut

    ~Score();   //destructeur
    void scoreCalculation();
};

#endif // SCORE_HPP_INCLUDED
