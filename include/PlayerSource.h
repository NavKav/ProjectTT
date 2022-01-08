//
// Created by navid on 04/06/2021.
//

#ifndef PROJECTTT_PLAYERSOURCE_H
#define PROJECTTT_PLAYERSOURCE_H

#include "DisplayerSource.h"

class PlayerSource {
public :
    PlayerSource(DisplayerSource* displayerSource);
    virtual void send(std::string s) const = 0;
protected :
    DisplayerSource* _displayerSource;
};


#endif //PROJECTTT_PLAYERSOURCE_H
