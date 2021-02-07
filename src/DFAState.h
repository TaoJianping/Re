//
// Created by tao on 2021/1/19.
//

#ifndef RETEST_DFASTATE_H
#define RETEST_DFASTATE_H
#include <utility>
#include <vector>
#include "NFAState.h"

class DFAState {
private:
    bool isEnd = false;
    std::vector<NFAState* > NFAStates {};
    std::map<char, DFAState*> transition {};
    std::string description{};
public:
    const std::string& desc();
    void setDesc(std::string d);
    explicit DFAState(std::vector<NFAState* > states) : NFAStates(std::move(states)) {
        for (auto s : NFAStates) {
            if (s->isEnd) {
                this->isEnd = true;
                break;
            }
        }
    };
    DFAState() = default;;
    std::vector<NFAState* > getNFAStates();
    bool setPath(char c, DFAState* state);
    bool containsPath(char c);
    DFAState* pathTo(char c);
    [[nodiscard]] bool End() const;
    std::map<char, DFAState*> getAllPath();
    void setEnd() { this->isEnd = true;};
};


#endif //RETEST_DFASTATE_H
