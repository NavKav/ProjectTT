//
// Created by navid on 14/05/2021.
//

#ifndef PROJECTTT_HITBOX_H
#define PROJECTTT_HITBOX_H

#include "GameEngine.h"

class Hitbox {
public :
    Hitbox(double a,double b,double c,double d, bool background, HitboxEffect* hitboxEffect);
    double getA() const;
    double getD() const;
    double getC() const;
    double getB() const;
    ~Hitbox();
    void effect(Ball* ball);
private :
    double _a, _b, _c, _d;

private:
    bool _background;
    std::shared_ptr<HitboxEffect> _hitboxEffect;
};


#endif //PROJECTTT_HITBOX_H
