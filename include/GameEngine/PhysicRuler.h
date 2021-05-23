//
// Created by navid on 14/05/2021.
//

#ifndef PROJECTTT_PHYSICRULER_H
#define PROJECTTT_PHYSICRULER_H

#include "DisplayerConnection.h"
#include "DisplayerSource.h"
#include "GameEngine/GameEngine.h"

class PhysicRuler : public DisplayerSource {
public:
    PhysicRuler(Ball* ball, DisplayerConnection* displayerConnection);
    void addHitbox(Hitbox *hitbox, string name);
    void checkNSetBall();
    void manageBall() const;
    void start();
    ~PhysicRuler();
    void stop();
    void lock();
    void unlock();
    void send(std::string s) const override;
private :
    Hitbox_map _hitboxMap;
    Ball *_ball;
    thread _thread;
    bool _boolThread = true;
    mutex _mutex;

};


#endif //PROJECTTT_PHYSICRULER_H
