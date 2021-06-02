//
// Created by navid on 14/05/2021.
//

#ifndef PROJECTTT_HITBOX_H
#define PROJECTTT_HITBOX_H

#include "GameEngine/GameEngine.h"

class Hitbox {
public :
    Hitbox(float a,float b,float c,float d, bool background, HitboxEffect* hitboxEffect);
    float getA() const;
    float getD() const;
    float getC() const;
    float getB() const;
    ~Hitbox();
    void effect(Ball* ball);
private :
    float _a, _b, _c, _d;

private:
    bool _background;
    std::shared_ptr<HitboxEffect> _hitboxEffect;
};


#endif //PROJECTTT_HITBOX_H
