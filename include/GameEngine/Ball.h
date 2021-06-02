//
// Created by navid on 15/05/2021.
//

#ifndef PROJECTTT_BALL_H
#define PROJECTTT_BALL_H

#include "GameEngine.h"

#define DELTA_T (double)0.2

class Ball {
public :
    float _x, _y, _x0, _y0, _xv0, _yv0;
public :
    Ball(float x, float y, BallTrajectory ballTrajectory);
    Ball();
    bool isIn(float a, float b, float c, float d) const;
    void newHitbox(Hitbox *hitbox);
    const string &getCurrentHitboxName() const;
    double getT() const;
    void move();
    void operator++(int i);
    void setCurrentHitboxName(const string &currentHitboxName);
    void setBallTrajectory(void (*ballTrajectory)(Ball *));
    void setV0();
    void operator+=(double i);
    void debug();
    void resetTime();

private :
    string _currentHitboxName = "";
    double _t = 0;

private:
    BallTrajectory _ballTrajectory;

};


#endif //PROJECTTT_BALL_H
