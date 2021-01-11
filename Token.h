//
// Created by tao on 2021/1/8.
//

#ifndef RE_TOKEN_H
#define RE_TOKEN_H

#endif //RE_TOKEN_H

enum class Token: char {
    CONCATENATION_OPERATOR = '#',
    UNION_OPERATOR = '|',
    CLOSURE_OPERATOR = '*',
    ZERO_OR_ONE_OPERATOR = '?',
    ONE_OR_MORE_OPERATOR = '+',
    GROUP_LEFT_OPERATOR = '(',
    GROUP_RIGHT_OPERATOR = ')',
};
