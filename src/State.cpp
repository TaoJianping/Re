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

void State::setEndStatus(bool status) {
    this->isEnd = status;
}

bool State::existPath(char path) const {
    return this->transition.count(path) > 0;
}

int State::epsilonTransitionSize() const {
    return this->epsilonTransition.size();
}

int State::transitionSize() const {
    return this->transition.size();
}

State* State::path(char c) const {
    return this->transition.at(c);
}
