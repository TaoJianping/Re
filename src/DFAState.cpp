//
// Created by tao on 2021/1/19.
//

#include <utility>
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

bool DFAState::End() const {
    return this->isEnd;
}

std::map<char, DFAState *> DFAState::getAllPath() {
    return this->transition;
}

const std::string& DFAState::desc() {
    return this->description;
}

void DFAState::setDesc(std::string d) {
    this->description = std::move(d);
}
