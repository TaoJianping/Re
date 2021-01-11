//
// Created by tao on 2021/1/8.
//

#ifndef RE_NFAGRAPH_H
#define RE_NFAGRAPH_H

#include <cctype>
#include "State.h"
#include <stack>

class NFA {
private:
    State* startState;
    State* endState;
public:
    NFA(State* start, State* end) : startState(start), endState(end) {};
    NFA build(const std::string& expr);
    static NFA createBasicNFA(char c);
    static NFA createConcatenation(NFA former, NFA back);
    static NFA createAlternatives(NFA former, NFA back);
};


#endif //RE_NFAGRAPH_H
