//
// Created by tao on 2021/1/14.
//

#include "DFA.h"

DFA::DFA(NFA nfa) {
    auto state = nfa.getStartState();
    auto es = this->eps_closure(state);
    auto ds = new DFAState(es);
    auto tokens = std::vector<char> {'a', 'b', 'c'};

    auto workList = std::vector<DFAState* >();
    workList.push_back(ds);




}

std::vector<State *> DFA::eps_closure(State *state) {
    auto res = std::vector<State *>();
    std::set<State* > visited;
    std::stack<State* > _stack;
    _stack.push(state);
    while (!_stack.empty()) {
        auto s = _stack.top();
        _stack.pop();
        for (auto iter = state->epsilonTransition.rbegin(); iter != state->epsilonTransition.rend(); ++iter)
        {
            if (visited.count(*iter) == 0) {
                _stack.push(*iter);;
            }
        }
        visited.insert(s);
        res.push_back(s);
    }
    return res;
}
