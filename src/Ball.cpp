//
// Created by navid on 15/05/2021.
//

#include "Ball.h"

Ball::Ball(double x, double y, BallTrajectory ballTrajectory) :
        _x(x),
        _y(y),
        _ballTrajectory(ballTrajectory){
    _x0 = x;
    _y0 = y;
}

Ball::Ball() :
        _x(0),
        _y(0),
        _ballTrajectory(drop){
    _x0 = _x;
    _y0 = _y;
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
    std::cout << _x << " : " << _y << std::endl;
}

void Ball::operator++(int i) {
    _t += DELTA_T;
}

void Ball::setCurrentHitboxName(const string &currentHitboxName) {
    _currentHitboxName = currentHitboxName;
}

void Ball::setBallTrajectory(void (*ballTrajectory)(Ball *)) {
    _ballTrajectory = ballTrajectory;
}
