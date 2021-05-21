//
// Created by navid on 14/05/2021.
//

#ifndef PROJECTTT_PHYSICRULER_H
#define PROJECTTT_PHYSICRULER_H

#include "GameEngine.h"

class PhysicRuler {
public:
    PhysicRuler(Ball* ball);
    void addHitbox(Hitbox *hitbox, string name);
    void checkNSetBall();
    void manageBall() const;
    void start();
    ~PhysicRuler();
    void stop();
    void lock();
    void unlock();
private :
    Hitbox_map _hitboxMap;
    Ball *_ball;
    thread _thread;
    bool _boolThread = true;
    mutex _mutex;

};


#endif //PROJECTTT_PHYSICRULER_H
