//
// Created by tao on 2021/1/7.
//

#ifndef RE_STATE_H
#define RE_STATE_H

#include <map>
#include <vector>
#include "Token.h"
#include <glog/logging.h>

static int StateCount = 0;

class State {
public:
    int id;
    bool isEnd;
    std::map<char, State*> transition;
    std::vector<State*> epsilonTransition;

    explicit State(bool isEnd = false) : isEnd(isEnd) {id = StateCount++;};
    void addTransition(char token, State* to);
    void addEpsilonTransition(State* to);
    void setEndStatus(bool status);
    [[nodiscard]] bool existPath(char path) const;
    [[nodiscard]] int epsilonTransitionSize() const;
    [[nodiscard]] int transitionSize() const;
    State* path(char c) const;
};

#endif //RE_STATE_H
