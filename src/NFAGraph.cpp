//
// Created by tao on 2021/1/8.
//

#include "NFAGraph.h"
#include "Utils.h"



NFA NFA::build(const std::string &originalExpr) {
    auto expr = m_to_b(insertExplicitConcatOperator(originalExpr));
    std::stack<NFA> _stack;

    for (char c : expr) {
        if (c == '|') {
            auto nfaBack = _stack.top();
            _stack.pop();
            auto nfaFormer = _stack.top();
            _stack.pop();
            auto nfa = NFA::createAlternatives(nfaFormer, nfaBack);
            _stack.push(nfa);
        }
        else if (c == '#') {
            auto nfaBack = _stack.top();
            _stack.pop();
            auto nfaFormer = _stack.top();
            _stack.pop();
            auto nfa = NFA::createConcatenation(nfaFormer, nfaBack);
            _stack.push(nfa);
        } else if (c == '*') {
            auto nfa = _stack.top();
            _stack.pop();
            auto n = NFA::createRepetition(nfa);
            _stack.push(n);
        }
        else if (isalpha(c)) {
            auto nfa = NFA::createBasicNFA(c);
            _stack.push(nfa);
        } else {
            LOG(ERROR) << "UNSUPPORT CHAR -> " << c;
            throw std::bad_exception();
        }
    }

    return _stack.top();
}

NFA NFA::createBasicNFA(char c) {
    auto start = new NFAState();
    auto end = new NFAState(true);

    start->addTransition(c, end);

    auto nfa = NFA(start, end);
    return nfa;
}

NFA NFA::createConcatenation(NFA former, NFA back) {
    former.endState->isEnd = false;
    former.endState->addEpsilonTransition(back.startState);

    auto nfa = NFA(former.startState, back.endState);
    return nfa;
}

NFA NFA::createAlternatives(NFA former, NFA back) {
    auto startState = new NFAState();
    auto endState = new NFAState(true);
    former.endState->setEndStatus(false);
    back.endState->setEndStatus(false);

    startState->addEpsilonTransition(former.startState);
    startState->addEpsilonTransition(back.startState);

    former.endState->addEpsilonTransition(endState);
    back.endState->addEpsilonTransition(endState);

    return NFA(startState, endState);
}

NFA NFA::createRepetition(NFA nfa) {
    auto startState = new NFAState();
    auto endState = new NFAState(true);

    startState->addEpsilonTransition(endState);
    startState->addEpsilonTransition(nfa.startState);
    nfa.endState->setEndStatus(false);
    nfa.endState->addEpsilonTransition(nfa.startState);
    nfa.endState->addEpsilonTransition(endState);

    return NFA(startState, endState);
}

NFAState *NFA::getStartState() {
    return this->startState;
}
