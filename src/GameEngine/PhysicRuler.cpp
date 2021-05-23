//
// Created by navid on 14/05/2021.
//

#include <unistd.h>
#include "GameEngine/PhysicRuler.h"


using namespace  std;

PhysicRuler::PhysicRuler(Ball* ball, DisplayerConnection* displayerConnection) :
        DisplayerSource(displayerConnection),
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

void PhysicRuler::manageBall() const{
    _ball->move();
}

void PhysicRuler::start() {
    while (_boolThread) {
        lock();
        checkNSetBall();
        manageBall();
        send("balle " + to_string(_ball->_x) + " " + to_string(_ball->_y));
        (*_ball)++;
        unlock();
        send("");
        Sleep(10);
    }
}

void PhysicRuler::checkNSetBall() {
    for (auto hitbox : _hitboxMap) {

        if (access( ("ressource/image/" + hitbox.first + ".png").c_str(), F_OK ) != -1) {
            send(hitbox.first + " " + to_string(hitbox.second->getA()) + " " + to_string(hitbox.second->getB()));
        }
        if (_ball->getCurrentHitboxName() != hitbox.first && _ball->isIn(hitbox.second->getA(), hitbox.second->getB(), hitbox.second->getC(), hitbox.second->getD())) {
            _ball->setCurrentHitboxName(hitbox.first);
            _ball->newHitbox(hitbox.second.get());
        }
    }
}

void PhysicRuler::stop() {
    _boolThread = false;
    _thread.join();
}

PhysicRuler::~PhysicRuler() {
    //std::cout << "calling ~PhysicRuler";
    stop();
    delete _ball;
}

void PhysicRuler::lock() {
    _mutex.lock();
}

void PhysicRuler::unlock() {
    _mutex.unlock();
}

void PhysicRuler::send(std::string s) const {
    _displayerConnection->receive(s);
}