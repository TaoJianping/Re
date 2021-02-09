//
// Created by tao on 2021/1/8.
//

#ifndef RE_NFAGRAPH_H
#define RE_NFAGRAPH_H

#include <cctype>
#include "NFAState.h"
#include <stack>

class NFA {
private:
    NFAState* startState;
    NFAState* endState;
public:
    NFA(NFAState* start, NFAState* end) : startState(start), endState(end) {};
    NFA() : startState(nullptr), endState(nullptr) {};
    static NFA build(const std::string& expr);
    NFAState* getStartState();
    static NFA createBasicNFA(char c);
    static NFA createConcatenation(NFA former, NFA back);
    static NFA createAlternatives(NFA former, NFA back);
    static NFA createRepetition(NFA nfa);
};


#endif //RE_NFAGRAPH_H
