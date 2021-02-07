//
// Created by tao on 2021/2/7.
//

#include <gtest/gtest.h>
#include <glog/logging.h>
#include "Utils.h"
#include "NFAGraph.h"
#include "DFA.h"
#include "MinimizeDFA.h"


TEST(TestKeyWord, IF)
{
    std::string keyWord("if");
    auto nfa = NFA::build(keyWord);
    auto dfa = DFA(nfa);
    auto minimizer = MinimizeDFA::Hopcroft();
    auto minimizedDFA = minimizer.minimize(dfa);
    auto startState = minimizedDFA.getStartState();
    EXPECT_EQ(startState->containsPath('i'), true);
    EXPECT_EQ(startState->pathTo('i')->End(), false);
    EXPECT_EQ(startState->pathTo('i')->containsPath('f'), true);
    auto fState = startState->pathTo('i')->pathTo('f');
    EXPECT_EQ(fState->End(), true);
    EXPECT_EQ(fState->getAllPath().size(), 0);
}

TEST(TestKeyWord, CLASS)
{
    std::string keyWord("class");
    auto nfa = NFA::build(keyWord);
    auto dfa = DFA(nfa);
    auto minimizer = MinimizeDFA::Hopcroft();
    auto minimizedDFA = minimizer.minimize(dfa);
    auto startState = minimizedDFA.getStartState();
    EXPECT_EQ(startState->containsPath('c'), true);
    auto cState = startState->pathTo('c');
    EXPECT_EQ(cState->containsPath('l'), true);
    auto lSate = cState->pathTo('l');
    EXPECT_EQ(lSate->containsPath('a'), true);
    auto aState = lSate->pathTo('a');
    EXPECT_EQ(aState->containsPath('s'), true);
    auto sState = aState->pathTo('s');
    EXPECT_EQ(sState->containsPath('s'), true);
    auto fsState = sState->pathTo('s');
    EXPECT_EQ(fsState->containsPath('s'), false);
    EXPECT_EQ(fsState->End(), true);
}
