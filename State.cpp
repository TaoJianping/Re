//
// Created by tao on 2021/1/7.
//

#include "State.h"


void State::addEpsilonTransition(State* to) {
    this->epsilonTransition.push_back(to);
}

void State::addTransition(char token, State *to) {
    this->transition[token] = to;
}
