//
// Created by tao on 2021/1/7.
//

#ifndef RE_STATE_H
#define RE_STATE_H

#include <map>
#include <vector>
#include <glog/logging.h>


class State {
public:
    bool isEnd;
    std::map<char, State*> transition;
    std::vector<State*> epsilonTransition;

    explicit State(bool isEnd = false);
    void addTransition(char token, State* to);
    void addEpsilonTransition(State* to);
};

#endif //RE_STATE_H
