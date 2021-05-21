//
// Created by navid on 21/05/2021.
//

#include "ChangeTrajectoryEffect.h"

ChangeTrajectoryEffect::ChangeTrajectoryEffect(BallTrajectory ballTrajectory) :
_ballTrajectory(ballTrajectory)
{

}
void ChangeTrajectoryEffect::effect(Ball* ball) {
    ball->setBallTrajectory(_ballTrajectory);
}
