//
// Created by tao on 2021/1/14.
//

#include "DFA.h"

DFA::DFA(NFA nfa) {
    auto state = nfa.getStartState();
    auto q0 = new DFAState(DFA::epsClosure(state));
    std::set<DFAState *> Q{};
    Q.insert(q0);
    std::queue<DFAState *> workList{};
    workList.push(q0);

    auto Alphabet = std::vector<char> {'a', 'b', 'c'};

    while (!workList.empty()) {
        auto q = workList.front();
        workList.pop();
        for (char c : Alphabet) {
            auto states = DFA::epsClosure(DFA::move(q->getNFAStates(), c));
//            auto newQ = new DFAState();
//            q->setPath(c, newQ);
//            Q.insert(newQ);
//            workList.push(newQ);
        }
    }



}


/*
 * eps_closure 的无递归版本，先注释了吧，没必要
 * */
//std::vector<State *> DFA::eps_closure(State *state) {
//    auto res = std::vector<State *>();
//    std::set<State* > visited;
//    std::stack<State* > _stack;
//    _stack.push(state);
//    while (!_stack.empty()) {
//        auto s = _stack.top();
//        _stack.pop();
//        for (auto iter = state->epsilonTransition.rbegin(); iter != state->epsilonTransition.rend(); ++iter)
//        {
//            if (visited.count(*iter) == 0) {
//                _stack.push(*iter);;
//            }
//        }
//        visited.insert(s);
//        res.push_back(s);
//    }
//    return res;
//}

/*
 * eps_closure 的递归版本，用这个
 *      目标是输入一个state，能够找到所有不消耗char能到达的边，就是ε边
 * */
void DFA::epsClosure(State *state, std::set<State *> &container) {
    if (container.count(state))
        return;
    container.insert(state);
    for (auto s : state->epsilonTransition) {
        epsClosure(s, container);
    }
}

std::vector<State *> DFA::epsClosure(const std::vector<State *> &T) {
    auto res = std::set<State *>{};

    for (auto s : T) {
        DFA::epsClosure(s, res);
    }

    return std::vector<State *>(res.begin(), res.end());
}

std::vector<State *> DFA::move(const std::vector<State *> &T, char c) {
    auto res = std::set<State *>{};
    for (auto s : T) {
        if (s->existPath(c)) {
            auto p = s->path(c);
            if (!res.count(p)) {
                res.insert(p);
            }
        }
    }
    return std::vector<State *>(res.begin(), res.end());
}

std::vector<State *> DFA::epsClosure(State *state) {
    auto container = std::set<State *>{};
    DFA::epsClosure(state, container);
    return std::vector<State *>(container.begin(), container.end());
}



