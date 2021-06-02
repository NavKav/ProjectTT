//
// Created by navid on 14/05/2021.
//

#include "GameEngine/Hitbox.h"

using namespace std;

Hitbox::Hitbox(float a,float b,float c,float d, bool background, HitboxEffect* hitboxEffect):
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

float Hitbox::getA() const {
    return _a;
}

float Hitbox::getB() const {
    return _b;
}

float Hitbox::getC() const {
    return _c;
}

float Hitbox::getD() const {
    return _d;
}

void Hitbox::effect(Ball* ball) {
    return _hitboxEffect->effect(ball);
}