//
// Created by navid on 15/05/2021.
//

#include "GameEngine/Ball.h"

Ball::Ball(double x, double y, BallTrajectory ballTrajectory) :
        _x(x),
        _y(y),
        _ballTrajectory(ballTrajectory){
    _x0 = x;
    _y0 = y;
    _xv0 = 0;
    _yv0 = 0;
}

Ball::Ball() :
        _x(0),
        _y(0),
        _ballTrajectory(drop){
    _x0 = _x;
    _y0 = _y;
    _xv0 = 0;
    _yv0 = 0;
}

bool Ball::isIn(double a, double b, double c, double d) const {
    return a <= _x &&
    _x <= c &&
    b <= _y &&
    _y <= d;
}

void Ball::newHitbox(Hitbox *hitbox) {
    std::cout << "new hitbox hit: " + _currentHitboxName << std::endl;
    hitbox->effect(this);
}

const string &Ball::getCurrentHitboxName() const {
    return _currentHitboxName;
}

double Ball::getT() const {
    return _t;
}

void Ball::move() {
    _ballTrajectory(this);
}

void Ball::debug() {
    std::cout << "(" << this<< ") " << _x << " : " << _y << std::endl;
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