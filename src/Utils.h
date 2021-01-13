//
// Created by tao on 2021/1/12.
//

#ifndef RE_UTILS_H
#define RE_UTILS_H

#include <string>
#include <stack>
#include <glog/logging.h>

void deleteAllMark(std::string &s, const std::string &mark);

std::string insertExplicitConcatOperator(const std::string &exp);

std::string m_to_b(const std::string& expr);


#endif //RE_UTILS_H
