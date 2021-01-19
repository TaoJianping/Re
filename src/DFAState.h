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
    std::vector<State* > states {};
public:
    explicit DFAState(std::vector<State* > states) : states(std::move(states)) {};
};


#endif //RETEST_DFASTATE_H
