//
// Created by navid on 22/05/2021.
//

#ifndef PROJECTTT_DISPLAYERCONNECTION_H
#define PROJECTTT_DISPLAYERCONNECTION_H

#include <thread>
#include <sstream>
#include <queue>
#include <stdio.h>
#include "Window.h"


class DisplayerConnection {
public :
    DisplayerConnection(Window* window);
    void start();
    void stop();
    ~DisplayerConnection();
    void receive(std::string s);

private :
    void chooseDisplay(std::string s);
    std::thread _thread;
    Window* _window;
    bool _boolThread = true;
    std::queue<std::istringstream> _queue;
};


#endif //PROJECTTT_DISPLAYERCONNECTION_H
