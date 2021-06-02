//
// Created by navid on 21/05/2021.
//

#include "GameEngine/ChangeTrajectoryEffect.h"

ChangeTrajectoryEffect::ChangeTrajectoryEffect(BallTrajectory ballTrajectory) :
_ballTrajectory(ballTrajectory)
{

}
void ChangeTrajectoryEffect::effect(Ball* ball) {
    ball->_x0 = ball->_x;
    ball->_y0 = ball->_y;
    ball->setV0();
    ball->setBallTrajectory(_ballTrajectory);
}
