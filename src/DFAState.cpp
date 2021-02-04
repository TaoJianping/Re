//
// Created by tao on 2021/1/19.
//

#include "DFAState.h"

std::vector<NFAState *> DFAState::getNFAStates() {
    return this->NFAStates;
}

bool DFAState::setPath(char c, DFAState* state) {
    this->transition[c] = state;
    return true;
}

bool DFAState::containsPath(char c) {
    return this->transition.count(c) != 0;
}

DFAState *DFAState::pathTo(char c) {
    return this->transition.at(c);
}

bool DFAState::End() {
    return this->isEnd;
}

std::map<char, DFAState *> DFAState::getAllPath() {
    return this->transition;
}
