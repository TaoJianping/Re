//
// Created by tao on 2021/1/8.
//


#include <string>
#include <stack>
#include "Token.h"

std::string insertExplicitConcatOperator(const std::string & exp) {
    std::string output;

    for (int i = 0; i < exp.length(); ++i) {
        const char token = exp[i];
        output += token;

        if (token == (char) Token::GROUP_LEFT_OPERATOR || token == (char) Token::UNION_OPERATOR)
            continue;

        if (i < exp.length() -1) {
            const char lookahead = exp[i+1];

            if (lookahead == (char) Token::CLOSURE_OPERATOR ||
                lookahead == (char) Token::GROUP_RIGHT_OPERATOR ||
                lookahead == (char) Token ::UNION_OPERATOR ) {
                continue;
            }

            output += (char) Token::CONCATENATION_OPERATOR;
        }
    }
    return output;
}