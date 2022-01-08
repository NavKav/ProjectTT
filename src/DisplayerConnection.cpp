//
// Created by navid on 22/05/2021.
//

#include "DisplayerConnection.h"

DisplayerConnection::DisplayerConnection(Window* window) :
_window(window)
{
    //_thread = std::thread(&DisplayerConnection::start, this);
}

void DisplayerConnection::start() {
    while (_boolThread) {
        while (!_queue.empty()) {
            chooseDisplay(_queue.front().str());
            _queue.pop();
        }
    }
}

void DisplayerConnection::stop() {
    _boolThread = false;
    //_thread.join();
}

DisplayerConnection::~DisplayerConnection() {
    stop();
}

void DisplayerConnection::receive(std::string s) {
    _queue.push(std::istringstream(s));
    chooseDisplay(_queue.front().str());
    _queue.pop();
}

void DisplayerConnection::chooseDisplay(std::string s) {
    if (s.size() == 0) {
        _window->refresh();
    } else {
        char name[50];
        float a, b;

        sscanf(s.c_str(), "%s %f %f",name, &a, &b);

        _window->drawIMG((int)a, (int) b, std::string(name) + ".png");
    }
}