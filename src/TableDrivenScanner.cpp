//
// Created by tao on 2021/2/5.
//

#include "TableDrivenScanner.h"

#include <utility>
#include "DFAState.h"
#include "NFAGraph.h"
#include "DFA.h"
#include "MinimizeDFA.h"


Lexeme::Token Lexer::TableDrivenScanner::nextToken() {
    std::string lexeme;
    DFAState* state = this->getStartState();

    while (state != nullptr) {

    }




    return Lexeme::Token();
}

Lexer::TableDrivenScanner::TableDrivenScanner(DFA dfa) {
    this->initialDFA = dfa;
    auto states = dfa.getAllStates();
    for (const auto& state : states) {
        for (auto [key, value] : state->getAllPath() ) {
            this->table[state][key] = value;
        }
    }
}

DFAState *Lexer::TableDrivenScanner::move(DFAState *state, char path) {
    if (this->table.count(state) == 0) {
        return nullptr;
    }
    auto _map = this->table.at(state);
    if (_map.count(path) == 0) {
        return nullptr;
    }

    return _map.at(path);
}

DFAState *Lexer::TableDrivenScanner::getStartState() {
    return this->initialDFA.getStartState();
}

