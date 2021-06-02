//
// Created by navid on 20/05/2021.
//

#include "GameEngine/TrajectoryFunction.h"

void drop(Ball* balle) {
    balle->_x = balle->_x0;

    balle->_y = (float) (
            (CONST_G)/2.0 *
            pow(balle->getT(), 2.0) +
            balle->_y0
    );
}

void topspin(Ball* balle) {
    balle->_x = (float) (
            balle->_xv0 *
            balle->getT() +
            balle->_x0
    );
    balle->_y = (float) (
            CONST_G / 2. *
            pow(balle->getT(), 2.) +
            balle->_yv0 *
            balle->getT() +
            balle->_y0
    );
}