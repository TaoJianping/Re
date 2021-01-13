//
// Created by tao on 2021/1/8.
//

#ifndef RE_TOKEN_H
#define RE_TOKEN_H

#endif //RE_TOKEN_H


//在本文实现范围中，优先级从小到大分别为
//
//连接符 ·
//闭包 *
//并 |

#include <map>




enum class Token: char {
    CONCATENATION_OPERATOR = '#',
    UNION_OPERATOR = '|',
    CLOSURE_OPERATOR = '*',
//    ZERO_OR_ONE_OPERATOR = '?',
//    ONE_OR_MORE_OPERATOR = '+',
    GROUP_LEFT_OPERATOR = '(',
    GROUP_RIGHT_OPERATOR = ')',
};

static std::map<char, int> OPERATOR_PRIORITY = {
        {static_cast<char>(Token::CONCATENATION_OPERATOR), 0},
        {static_cast<char>(Token::CLOSURE_OPERATOR), 1},
        {static_cast<char>(Token::UNION_OPERATOR), 2},
};

