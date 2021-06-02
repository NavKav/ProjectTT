//
// Created by navid on 24/05/2021.
//

#ifndef PROJECTTT_BOUNCEEFFECT_H
#define PROJECTTT_BOUNCEEFFECT_H

#include "GameEngine.h"

class BounceEffect : public HitboxEffect {
public :
    BounceEffect(float angle, float friction);
    void effect(Ball* ball) override;
private :
    float _angle;
    float _friction;

};


#endif //PROJECTTT_BOUNCEEFFECT_H
