//
// Created by navid on 21/05/2021.
//

#ifndef PROJECTTT_GAMEENGINE_H
#define PROJECTTT_GAMEENGINE_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <windows.h>
#include <cmath>
#include <queue>

class Ball;
class Hitbox;
class PhysicRuler;
class HitboxEffect;

//using namespace std;
typedef std::string string;
typedef std::thread thread;
typedef std::mutex mutex;
typedef std::unordered_map<string, std::shared_ptr<Hitbox>> Hitbox_map;
typedef void (*BallTrajectory)(Ball* ball);

#include "TrajectoryFunction.h"
#include "Hitbox.h"
#include "GameEngine/Ball.h"
#include "HitboxEffect.h"
#include "PhysicRuler.h"
#include "GameEngine/ChangeTrajectoryEffect.h"
#include "GameEngine/BounceEffect.h"

#define CONST_G 9.81

#endif //PROJECTTT_GAMEENGINE_H
