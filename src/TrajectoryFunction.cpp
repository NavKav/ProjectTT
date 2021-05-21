//
// Created by navid on 20/05/2021.
//

#include "TrajectoryFunction.h"

void drop(Ball* balle) {
    balle->_x = balle->_x0;

    balle->_y = (double) (
            (CONST_G)/2.0 *
            pow(balle->getT(), 2.0) +
            balle->_y0
    );
}