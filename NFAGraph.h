//
// Created by tao on 2021/1/8.
//

#ifndef RE_NFAGRAPH_H
#define RE_NFAGRAPH_H

#include "State.h"
#include <stack>

class NFA {
private:
    State* startState;
    State* endState;
public:
    NFA();
    NFA(State* start, State* end) : startState(start), endState(end) {};
    NFA build(const std::string& expr);
    static NFA createBasicNFA(char c);
};


#endif //RE_NFAGRAPH_H
