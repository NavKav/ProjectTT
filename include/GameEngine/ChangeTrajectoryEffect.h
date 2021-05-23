//
// Created by navid on 21/05/2021.
//

#ifndef PROJECTTT_CHANGETRAJECTORYEFFECT_H
#define PROJECTTT_CHANGETRAJECTORYEFFECT_H

#include "GameEngine.h"

class ChangeTrajectoryEffect : public HitboxEffect{
public :
    void effect(Ball* ball) override;
    ChangeTrajectoryEffect(BallTrajectory ballTrajectory);
private:
    BallTrajectory _ballTrajectory;
};


#endif //PROJECTTT_CHANGETRAJECTORYEFFECT_H
