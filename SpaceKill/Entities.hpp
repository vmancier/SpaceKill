/********************************************************************************************
 * Project: SpaceKill
 * File: Entities.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef ENTITIES_HPP_INCLUDED
#define ENTITIES_HPP_INCLUDED

/************* GAME_MODEL ************/
const int MODEL_WIDTH = 440;
const int MODEL_HEIGHT = 720;

/************* GAME_VIEW ************/
const int VIEW_WIDTH = 440;
const int VIEW_HEIGHT = 720;
const int VIEW_BPP = 32;

/************* PLAYER ************/
const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 50;
const float PLAYER_X_SPEED = 200.0;
const float PLAYER_Y_SPEED = 40.0;

/************* ENEMY ************/
const int DEFAULT_ENEMY_WIDTH = 30;
const int DEFAULT_ENEMY_HEIGHT = 50;
const float DEFAULT_ENEMY_X_SPEED = 50.0;
const float DEFAULT_ENEMY_Y_SPEED = 100.0;
const int DEFAULT_ENEMY_HEALTH = 100;
const int DEFAULT_ENEMY_STYLESHOT = 1;
const int DEFAULT_ENEMY_VALUE = 10;
const float COEF_1 = 1.0;
const float COEF_2 = 1.2;
const float COEF_3 = 1.4;
const float COEF_4 = 1.6;
const float COEF_5 = 1.8;
const float COEF_6 = 2.0;
const float COEF_7 = 2.2;
const float COEF_8 = 2.4;

/************* SHOTS ************/
const float DEFAULT_SHOT_FIRERATE = 0.50;
#endif // ENTITIES_HPP_INCLUDED
