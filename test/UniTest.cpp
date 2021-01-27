//
// Created by tao on 2021/1/12.
//

#include "UniTest.h"


TEST(Base, Normal)
{
    std::string expr = "a(b|c)*";
    deleteAllMark(expr, " ");
    auto e = insertExplicitConcatOperator(expr);
    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = m_to_b(e);
    auto nfa = NFA();
    auto res = nfa.build(te);
    auto startState = res.getStartState();
    EXPECT_EQ(startState->epsilonTransition.size(), 0);
    EXPECT_EQ(startState->transition.size(), 1);
    EXPECT_EQ(startState->transition.count('a'), 1);
    EXPECT_EQ(startState->transition['a']->epsilonTransition.size(), 1);
    EXPECT_EQ(startState->transition['a']->epsilonTransition[0]->epsilonTransition.size(), 2);
    auto n2 = startState->transition['a']->epsilonTransition[0];
    EXPECT_EQ(n2->epsilonTransition.size(), 2);
    for (auto s : n2->epsilonTransition) {
        if (s->isEnd) {
            LOG(INFO) << "FIND END STATE";
        } else {
            auto n3 = s;
            LOG(INFO) << "n3's id ==> " << n3->id;
            EXPECT_EQ(n3->epsilonTransitionSize(), 2);
            EXPECT_EQ(n3->transitionSize(), 0);
            for (auto s1 : n3->epsilonTransition) {
                EXPECT_TRUE(s1->existPath('b') || s1->existPath('c'));
                if (s1->existPath('b')) {
                    auto n5 = s1->path('b');
                    EXPECT_EQ(n5->epsilonTransitionSize(), 1);
                    auto n8 = n5->epsilonTransition[0];
                    EXPECT_EQ(n8->epsilonTransitionSize(), 2);
                    for (auto s2 : n8->epsilonTransition) {
                        if (s2->isEnd) {
                            LOG(INFO) << "FIND END STATE! id -> " << s2->id;
                        } else {
                            EXPECT_EQ(s2->id, n3->id);
                        }
                    }
                }
            }
        }
    }
}


TEST(TestDFA, success) {
    std::string expr = "a(b|c)*";
    deleteAllMark(expr, " ");
    auto e = insertExplicitConcatOperator(expr);
    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = m_to_b(e);
    auto nfa = NFA();
    auto res = nfa.build(te);
    auto dfa = DFA(res);
    EXPECT_EQ(1, 1);
}

TEST(TestDFA, success2) {
    std::string expr = "(a|b)*abb";
    deleteAllMark(expr, " ");
    auto e = insertExplicitConcatOperator(expr);
//    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = m_to_b(e);
    auto nfa = NFA();
    auto res = nfa.build(te);
    auto dfa = DFA(res);
    auto A = dfa.getStartState();
    EXPECT_EQ(A->containsPath('b'), true);
    EXPECT_EQ(A->containsPath('c'), false);
    EXPECT_EQ(A->containsPath('a'), true);
    auto B = A->pathTo('a');
    auto C = A->pathTo('b');
    EXPECT_EQ(B->End(), false);
    EXPECT_EQ(B->containsPath('b'), true);
    EXPECT_EQ(B->containsPath('c'), false);
    EXPECT_EQ(B->containsPath('a'), true);
    EXPECT_EQ(C->End(), false);
    EXPECT_EQ(C->containsPath('b'), true);
    EXPECT_EQ(C->containsPath('c'), false);
    EXPECT_EQ(C->containsPath('a'), true);
    EXPECT_EQ(C->pathTo('a'), B);
    EXPECT_EQ(C->pathTo('b'), C);
    auto D = B->pathTo('b');
    EXPECT_EQ(D->End(), false);
    EXPECT_EQ(C->containsPath('b'), true);
    auto E = D->pathTo('b');
    EXPECT_EQ(E->End(), true);
    EXPECT_EQ(E->pathTo('a'), B);

}