//
// Created by tao on 2021/1/19.
//

#ifndef RETEST_DFASTATE_H
#define RETEST_DFASTATE_H
#include <utility>
#include <vector>
#include "State.h"

class DFAState {
private:
    std::vector<State* > NFAStates {};
    std::map<char, DFAState*> transition {};
public:
    explicit DFAState(std::vector<State* > states) : NFAStates(std::move(states)) {};
    std::vector<State* > getNFAStates();
    bool setPath(char c, DFAState* state);
};


#endif //RETEST_DFASTATE_H
