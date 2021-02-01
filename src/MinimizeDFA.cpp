//
// Created by tao on 2021/1/27.
//

#include "MinimizeDFA.h"


/*
 * 1. 要把所有的states分成Accept和NonAccept的两个集合（MiddleNode）
 * 2. 对每个状态里面的每个state，如果输入的字符不能转换到一样的
 * */
MinimizeDFA MinimizeDFA::hopcroft(DFA dfa) {
    auto states = dfa.getAllStates();
    std::vector<MiddleNode> P = MinimizeDFA::splitStatesToNA(states);
    std::map<DFAState *, int> _map;
    for (const auto &p : P) {
        for (auto state : p.states) {
            _map[state] = p.id;
        }
    }

    bool goOn = true;
    while (goOn) {
        decltype(P.begin()) iter;
        std::vector<MiddleNode> resSet{};
        for (iter = P.begin(); iter != P.end(); ++iter) {
            if (!iter->splitFinished) {
                resSet = MinimizeDFA::split(*iter, _map);
                if (resSet.size() == 1) {
                    iter->splitFinished = true;
                } else {
                    break;
                }
            }
        }

        if (iter != P.end()) {
            P.erase(iter);
            P.insert(iter, resSet.begin(), resSet.end());
            _map.clear();
            for (const auto &p : P) {
                for (auto state : p.states) {
                    _map[state] = p.id;
                }
            }
        }
        if (std::all_of(P.begin(), P.end(), [](const MiddleNode& item) { return item.splitFinished; })) {
            goOn = false;
        }
    }

    return MinimizeDFA();
}

std::vector<MiddleNode> MinimizeDFA::splitStatesToNA(const std::vector<DFAState *> &states) {
    MiddleNode AcceptSet{};
    MiddleNode NonAcceptSet{};

    for (auto &state : states) {
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

std::vector<MiddleNode> MinimizeDFA::split(MiddleNode middleNode, std::map<DFAState *, int> _map) {
    std::vector<char> Alphabet{'f', 'e', 'i'};
    std::map<int, std::vector<DFAState *>> record;

    for (auto c : Alphabet) {
        for (auto state : middleNode.states) {
            DFAState *path;
            if (state->containsPath(c)) {
                path = state->pathTo(c);
            } else {
                path = state;
            }

            auto setNum = _map.at(path);
            record[setNum].push_back(state);
        }
        if (record.size() > 1) {
            std::vector<MiddleNode> res;
            for (auto[key, states] : record) {
                auto m = MiddleNode();
                m.states = std::move(states);
                res.push_back(m);
            }
            return res;
        } else {
            record.clear();
        };
    };

    std::vector<MiddleNode> res;
    res.push_back(middleNode);
    return res;
}