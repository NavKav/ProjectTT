//
// Created by navid on 24/05/2021.
//

#include "GameEngine/BounceEffect.h"

BounceEffect::BounceEffect(float angle, float friction) :
_angle(angle),
_friction(friction)
{

}

void BounceEffect::effect(Ball *ball) {

    ball->setV0();

    ball->_x0 = ball->_x;
    ball->_y0 = ball->_y;

    //std::cout << "ici : " << ball->_xv0 << "  " << ball->_yv0<< std::endl;
    ball->_xv0 = ball->_xv0 * cos(_angle) +
            ball->_yv0 * sin(_angle);
    ball->_yv0 = ball->_xv0 * sin(_angle) -
                 ball->_yv0 * cos(_angle);

    ball->_xv0 /= _friction;
    ball->_yv0 /= _friction;

    ball->resetTime();

}