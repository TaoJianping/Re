//
// Created by tao on 2021/2/5.
//

#include "TableDrivenScanner.h"

#include <utility>
#include "DFAState.h"
#include "NFAGraph.h"
#include "DFA.h"
#include "MinimizeDFA.h"


void Lexer::TableDrivenScanner::defineRules() {

}

void Lexer::TableDrivenScanner::addKeyWord(const std::string &keyword) {

}

void Lexer::TableDrivenScanner::defineRulesWithDefault() {

}

Lexeme::Token Lexer::TableDrivenScanner::nextToken() {
    std::string lexeme;
    DFAState* state = nullptr;






    return Lexeme::Token();
}

