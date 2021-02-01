//
// Created by tao on 2021/1/27.
//

#ifndef RETEST_MINIMIZEDFA_H
#define RETEST_MINIMIZEDFA_H

#include "DFA.h"
#include <algorithm>



static int MiddleNodeCount = 0;

struct MiddleNode {
    int id = MiddleNodeCount++;
    bool splitFinished = false;
    std::vector<DFAState *> states;
};


class MinimizeDFA {
public:
    static MinimizeDFA hopcroft(DFA dfa);
    static std::vector<MiddleNode> splitStatesToNA(const std::vector<DFAState *>& states);
    static std::vector<MiddleNode> split(MiddleNode node, std::map<DFAState *, int> _map);
};


#endif //RETEST_MINIMIZEDFA_H
