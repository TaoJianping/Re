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
#include "NFAState.h"
#include "DFAState.h"

class DFA {
private:
    static void epsClosure(NFAState* state, std::set<NFAState*>& container);
    DFAState* startState;
public:
    explicit DFA(NFA nfa);
    DFA() {};
    void setStartState(DFAState* startState) { this->startState = startState;};
    static std::vector<NFAState*> epsClosure(const std::vector<NFAState*>& T);
    static std::vector<NFAState*> epsClosure(NFAState* state);
    static std::vector<NFAState*> move(const std::vector<NFAState*>& T, char c);
    static bool containStates(const std::set<DFAState *>& Q, const std::vector<NFAState *>& states);
    static std::optional<DFAState *> getDFAState(const std::set<DFAState *>& Q, const std::vector<NFAState *>& states);
    DFAState* getStartState();
    std::vector<DFAState *> getAllStates();
};


#endif //RETEST_DFA_H
