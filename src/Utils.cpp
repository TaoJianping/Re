//
// Created by tao on 2021/1/8.
//


#include "Utils.h"
#include "Token.h"


void deleteAllMark(std::string &s, const std::string &mark) {
    size_t nSize = mark.size();
    while (true) {
        size_t pos = s.find(mark);    //  尤其是这里
        if (pos == std::string::npos) {
            return;
        }

        s.erase(pos, nSize);
    }
}

std::string insertExplicitConcatOperator(const std::string &exp) {
    std::string output;

    for (int i = 0; i < exp.length(); ++i) {
        const char token = exp[i];
        output += token;

        if (token == (char) Token::GROUP_LEFT_OPERATOR || token == (char) Token::UNION_OPERATOR)
            continue;

        if (i < exp.length() - 1) {
            const char lookahead = exp[i + 1];

            if (lookahead == (char) Token::CLOSURE_OPERATOR ||
                lookahead == (char) Token::GROUP_RIGHT_OPERATOR ||
                lookahead == (char) Token::UNION_OPERATOR) {
                continue;
            }

            output += (char) Token::CONCATENATION_OPERATOR;
        }
    }
    return output;
}

std::string m_to_b(const std::string &expr) {
    LOG(INFO) << "START Shunting Yard Algorithm";
    LOG(INFO) << "EXPR -> " << expr;

    std::stack<char> optStack;
    std::string output;

    for (char c : expr) {
        if (c == static_cast<char>(Token::GROUP_LEFT_OPERATOR)) {
            optStack.push(c);
        } else if (isalnum(c)) {
            output += c;
        } else if (c == static_cast<char>(Token::CLOSURE_OPERATOR) ||
                   c == static_cast<char>(Token::CONCATENATION_OPERATOR) ||
                   c == static_cast<char>(Token::UNION_OPERATOR)) {
            if (optStack.empty()) {
                optStack.push(c);
                continue;
            }
            if (optStack.top() == static_cast<char>(Token::GROUP_LEFT_OPERATOR)) {
                optStack.push(c);
                continue;
            }

            while (!optStack.empty() && OPERATOR_PRIORITY[optStack.top()] > OPERATOR_PRIORITY[c]) {
                output.push_back(optStack.top());
                optStack.pop();
            }
            optStack.push(c);
        } else if (c == static_cast<char>(Token::GROUP_RIGHT_OPERATOR)) {
            while (optStack.top() != static_cast<char>(Token::GROUP_LEFT_OPERATOR)) {
                auto i = optStack.top();
                optStack.pop();
                output.push_back(i);
            }
            if (optStack.top() == static_cast<char>(Token::GROUP_LEFT_OPERATOR)) {
                optStack.pop();
            } else {
                LOG(ERROR) << "Could Not Find LEFT_OPERATOR";
                exit(-1);
            }
        } else {
            LOG(ERROR) << "NOT SUPPORT operator or char !";
            exit(-1);
        }
    }

    while (!optStack.empty()) {
        output += optStack.top();
        optStack.pop();
    }

    LOG(INFO) << "Output -> " << output;
    return output;
}
