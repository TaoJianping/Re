//
// Created by tao on 2021/2/5.
//

#ifndef RETEST_SCANNER_H
#define RETEST_SCANNER_H

#include <string>


class Scanner {
public:
    void defineRules();
    void addKeyWord(const std::string& keyword);
};


#endif //RETEST_SCANNER_H
