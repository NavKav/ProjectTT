//
// Created by navid on 04/06/2021.
//

#ifndef PROJECTTT_PLAYER_H
#define PROJECTTT_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "PlayerSource.h"

#define NUM_SDLK 1000

class Player : PlayerSource{
public :
    Player(DisplayerSource* displayerSource);
    void send(std::string s) const;
    void start();
    void stop();
    ~Player();
private :
    bool _boolLoop = true;
    struct Input {
        bool pressed;
        unsigned int u,v;
    };
    Input _inputArr[NUM_SDLK] = {{false, 0, 0}};
    void manageInput();
    void takeInput(const SDL_Event& event);
};


#endif //PROJECTTT_PLAYER_H
