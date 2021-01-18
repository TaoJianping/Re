//
// Created by tao on 2021/1/14.
//

#ifndef RETEST_DFA_H
#define RETEST_DFA_H

#include "NFAGraph.h"
#include <vector>
#include <stack>
#include <set>
#include "State.h"

class DFA {
public:
    explicit DFA(NFA nfa);
    std::vector<State*> eps_closure(State* state);
};


#endif //RETEST_DFA_H
