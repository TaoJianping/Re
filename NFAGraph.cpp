//
// Created by tao on 2021/1/8.
//

#include "NFAGraph.h"

NFA NFA::build(const std::string &expr) {
    std::stack<NFA> _stack;

    for (char c : expr) {
        if (c == '|') {

        } else {

        }
    }

    return NFA(nullptr, nullptr);
}

NFA::NFA() {

}

NFA NFA::createBasicNFA(char c) {
    auto start = new State();
    auto end = new State(true);

    start->addTransition(c, end);

    auto nfa = NFA(start, end);
    return nfa;
}
