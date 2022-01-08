//
// Created by navid on 22/05/2021.
//

#ifndef PROJECTTT_DISPLAYERSOURCE_H
#define PROJECTTT_DISPLAYERSOURCE_H

#include <sstream>
#include "DisplayerConnection.h"

class DisplayerSource {
public :
    DisplayerSource(DisplayerConnection* displayerConnection);
    virtual void send(std::string s) const = 0;
    virtual void receive(std::string s){};
protected:
    DisplayerConnection* _displayerConnection;
};


#endif //PROJECTTT_DISPLAYERSOURCE_H
