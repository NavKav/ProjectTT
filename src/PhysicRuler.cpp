//
// Created by navid on 14/05/2021.
//

#include "PhysicRuler.h"

using namespace  std;

PhysicRuler::PhysicRuler(Ball* ball) :
_ball(ball)
{
    _thread = thread(&PhysicRuler::start, this);
}

void PhysicRuler::addHitbox(Hitbox *hitbox, string name) {
    lock();
    if (_hitboxMap.find(name) != _hitboxMap.end()) {
        std::cout << "addHitbox() : The given Hitbox key " << "\"" << name << "\"" << "  already exists.(might leads to memory leak)"<< std::endl;
    } else {
        _hitboxMap[name] = std::shared_ptr<Hitbox>(hitbox);
    }
    unlock();
}

void PhysicRuler::checkNSetBall() {
    for (auto hitbox : _hitboxMap) {
        if (_ball->getCurrentHitboxName() != hitbox.first && _ball->isIn(hitbox.second->getA(), hitbox.second->getB(), hitbox.second->getC(), hitbox.second->getD())) {
            _ball->setCurrentHitboxName(hitbox.first);
            _ball->newHitbox(hitbox.second.get());
        }
    }
}

void PhysicRuler::manageBall() const{
    _ball->move();
}

void PhysicRuler::start() {
    while (_boolThread) {
        lock();
        checkNSetBall();
        manageBall();
        (*_ball)++;
        unlock();
        Sleep(10);
    }
}

void PhysicRuler::stop() {
    _boolThread = false;
    _thread.join();
}

PhysicRuler::~PhysicRuler() {
    stop();
    delete _ball;
}

void PhysicRuler::lock() {
    _mutex.lock();
}

void PhysicRuler::unlock() {
    _mutex.unlock();
}
