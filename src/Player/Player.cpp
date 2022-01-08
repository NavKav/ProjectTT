//
// Created by navid on 04/06/2021.
//

#include "Player/Player.h"

Player::Player(DisplayerSource* displayerSource) :
        PlayerSource(displayerSource) {
}

void Player::send(std::string s) const{
    _displayerSource->receive(s);
}

void Player::start() {
    while(_boolLoop) {
        SDL_Event input;
        while(SDL_PollEvent(&input)) {
            takeInput(input);
            manageInput();
        }
    }
}

void Player::stop() {
    _boolLoop = false;
}

Player::~Player() {
}

void Player::manageInput() {
    if (_inputArr[SDLK_ESCAPE].pressed) {
        send("");
        stop();
    }
    if (_inputArr[SDLK_a].pressed) {
        send("la lettre A");
    }
}

void Player::takeInput(const SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        send("");
        stop();
    }
    //std::cout << "(Player) received : " + event.key.keysym.scancode << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "une touche est enfoncée\n";
        _inputArr[event.key.keysym.sym] = {true, 0, 0};
    } else if (event.type == SDL_KEYUP) {
        std::cout << "une touche est relâchée\n";
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    }
}