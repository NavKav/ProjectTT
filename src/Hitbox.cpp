//
// Created by navid on 14/05/2021.
//

#include "Hitbox.h"

using namespace std;

Hitbox::Hitbox(double a,double b,double c,double d, bool background, HitboxEffect* hitboxEffect):
_a(a),
_b(b),
_c(c),
_d(d),
_background(background),
_hitboxEffect(hitboxEffect)
{

}

Hitbox::~Hitbox() {
    //std::cout << "Hitbox détruite !" << std::endl;
}

double Hitbox::getA() const {
    return _a;
}

double Hitbox::getB() const {
    return _b;
}

double Hitbox::getC() const {
    return _c;
}

double Hitbox::getD() const {
    return _d;
}

void Hitbox::effect(Ball* ball) {
    return _hitboxEffect->effect(ball);
}