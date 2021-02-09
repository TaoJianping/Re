//
// Created by tao on 2021/2/5.
//

#ifndef RETEST_TABLEDRIVENSCANNER_H
#define RETEST_TABLEDRIVENSCANNER_H

#include <string>
#include "Lexeme.h"

namespace Lexer {
    using namespace Lexeme;

    class TableDrivenScanner {
    public:
        void defineRules();
        void defineRulesWithDefault();
        void addKeyWord(const std::string& keyword);
        Token nextToken();
    };

}


#endif //RETEST_TABLEDRIVENSCANNER_H
