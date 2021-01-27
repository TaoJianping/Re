//
// Created by tao on 2021/1/19.
//

#ifndef RETEST_DFASTATE_H
#define RETEST_DFASTATE_H
#include <utility>
#include <vector>
#include "State.h"

class DFAState {
private:
    bool isEnd = false;
    std::vector<State* > NFAStates {};
    std::map<char, DFAState*> transition {};
public:
    explicit DFAState(std::vector<State* > states) : NFAStates(std::move(states)) {
        for (auto s : NFAStates) {
            if (s->isEnd) {
                this->isEnd = true;
                break;
            }
        }
    };
    std::vector<State* > getNFAStates();
    bool setPath(char c, DFAState* state);
    bool containsPath(char c);
    DFAState* pathTo(char c);
    bool End();
    std::map<char, DFAState*> getAllPath();
};


#endif //RETEST_DFASTATE_H
