//
// Created by tao on 2021/1/19.
//

#include "DFAState.h"

std::vector<State *> DFAState::getNFAStates() {
    return this->NFAStates;
}

bool DFAState::setPath(char c, DFAState* state) {
    this->transition[c] = state;
    return true;
}
