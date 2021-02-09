//
// Created by tao on 2021/2/9.
//

#include <gtest/gtest.h>
#include <glog/logging.h>
#include "Lexicon.h"



TEST(TestLexicon, success)
{
    auto lex = Lexer::Lexicon();
    lex.defineRulesWithDefault();
    auto dfa = lex.getDFA();
}