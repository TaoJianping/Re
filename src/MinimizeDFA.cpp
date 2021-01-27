//
// Created by tao on 2021/1/27.
//

#include "MinimizeDFA.h"



/*
 * 1. 要把所有的states分成Accept和NonAccept的两个集合（MiddleNode）
 * 2. 对每个状态里面的每个state，如果输入的字符不能转换到一样的
 * */
MinimizeDFA *MinimizeDFA::minimize(DFA dfa) {
    auto states = dfa.getAllStates();
    std::vector<MiddleNode> P = MinimizeDFA::splitStatesToNA(states);
    std::map<DFAState *, int> _map;
    for (const auto& p : P) {
        for (auto state : p.states) {
            _map[state] = p.id;
        }
    }







}

std::vector<MiddleNode> MinimizeDFA::splitStatesToNA(const std::vector<DFAState *>& states) {
    MiddleNode AcceptSet {};
    MiddleNode NonAcceptSet {};

    for (auto& state : states) {
        if (state->End()) {
            AcceptSet.states.push_back(state);
        } else {
            NonAcceptSet.states.push_back(state);
        }
    };

    std::vector<MiddleNode> res{};
    res.push_back(AcceptSet);
    res.push_back(NonAcceptSet);
    return res;
}

std::vector<MiddleNode> MinimizeDFA::split(const std::vector<MiddleNode> sets) {
    for (auto p : sets) {
        for (auto state : p.states) {

        }
    }
}
