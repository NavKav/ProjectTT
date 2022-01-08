//
// Created by navid on 15/05/2021.
//

#include "GameEngine/Ball.h"

Ball::Ball(float x, float y, BallTrajectory ballTrajectory) :
        _x(x),
        _y(y),
        _ballTrajectory(ballTrajectory){
    _x0 = x;
    _y0 = y;
    _xv0 = 0;
    _yv0 = 0;
}

Ball::Ball() :
        _x(700),
        _y(350),
        _ballTrajectory(parabola){
    _x0 = _x;
    _y0 = _y;
    _xv0 = -10;
    _yv0 = -10;
}

bool Ball::isIn(float a, float b, float c, float d) const {
    return a <= _x &&
    _x <= c &&
    b <= _y &&
    _y <= d;
}

void Ball::newHitbox(Hitbox *hitbox) {
    //std::cout << "------------------- new hitbox hit: " + _currentHitboxName << " -------------------" << std::endl;
    hitbox->effect(this);
}

const string &Ball::getCurrentHitboxName() const {
    return _currentHitboxName;
}

double Ball::getT() const {
    return _t;
}

void Ball::move() {
    if (_ballTrajectory != nullptr) {
        _ballTrajectory(this);
    }
}

void Ball::debug() {
    std::cout << "(t = " << getT() <<") " << /*"(" << this<< ") " <<*/ _x << " : " << _y << std::endl;
    std::cout << "                              (" << this<< ") " << "v0 = " << _xv0 << " : " << _yv0 << std::endl;
}

void Ball::operator++(int i) {
    _t += DELTA_T;
}

void Ball::operator+=(double i) {
    _t += i;
}

void Ball::setCurrentHitboxName(const string &currentHitboxName) {
    _currentHitboxName = currentHitboxName;
}

void Ball::setBallTrajectory(void (*ballTrajectory)(Ball *)) {
    _ballTrajectory = ballTrajectory;
}

void Ball::setV0() {
    Ball aux = *this;
    aux+= 0.0001;
    aux.move();
    _xv0 = (aux._x - _x) / 0.0001;
    _yv0 = (aux._y - _y) / 0.0001;
}

void Ball::resetTime() {
    _t = 0;
}

bool Ball::getHasReachedAir() const {
    return _hasReachedAir;
}

void Ball::setHasReachedAir(bool hasReachedAir) {
    _hasReachedAir = hasReachedAir;
}
