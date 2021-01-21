//
// Created by tao on 2021/1/14.
//

#ifndef RETEST_DFA_H
#define RETEST_DFA_H

#include "NFAGraph.h"
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include "State.h"
#include "DFAState.h"

class DFA {
private:
    static void epsClosure(State* state, std::set<State*>& container);

public:
    explicit DFA(NFA nfa);
    static std::vector<State*> epsClosure(const std::vector<State*>& T);
    static std::vector<State*> epsClosure(State* state);
    static std::vector<State*> move(const std::vector<State*>& T, char c);
};


#endif //RETEST_DFA_H
