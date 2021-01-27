//
// Created by tao on 2021/1/27.
//

#ifndef RETEST_MINIMIZEDFA_H
#define RETEST_MINIMIZEDFA_H

#include "DFA.h"

static int MiddleNodeCount = 0;

struct MiddleNode {
    int id = MiddleNodeCount++;
    std::vector<DFAState *> states;
};




class MinimizeDFA {
public:
    MinimizeDFA* minimize(DFA dfa);
    static std::vector<MiddleNode> splitStatesToNA(const std::vector<DFAState *>& states);
    static std::vector<MiddleNode> split(const std::vector<MiddleNode> sets);
};


#endif //RETEST_MINIMIZEDFA_H
