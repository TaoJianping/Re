//
// Created by tao on 2021/1/12.
//

#include "UniTest.h"


TEST(Base, Normal)
{
    std::string expr = "a(b|c)*";
    deleteAllMark(expr, " ");
    auto e = NFA::insertExplicitConcatOperator(expr);
    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = NFA::m_to_b(e);
    auto nfa = NFA::NFAGraph();
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
    auto e = NFA::insertExplicitConcatOperator(expr);
    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = NFA::m_to_b(e);
    auto nfa = NFA::NFAGraph();
    auto res = nfa.build(te);
    auto dfa = DFA(res);
    auto hopcroft = MinimizeDFA::Hopcroft();
    auto finalDFA = hopcroft.minimize(dfa);


//    auto mini = MinimizeDFA::hopcroft(dfa);
}

TEST(TestDFA, success2) {
    std::string expr = "(a|b)*abb";
    deleteAllMark(expr, " ");
    auto e = NFA::insertExplicitConcatOperator(expr);
//    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = NFA::m_to_b(e);
    auto nfa = NFA::NFAGraph();
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

TEST(TestDFA, success3) {
//    std::string expr = "fee|fie";
//    auto dfa_0 = new DFAState();
//    auto dfa_1 = new DFAState();
//    auto dfa_2 = new DFAState();
//    auto dfa_3 = new DFAState();
//    auto dfa_4 = new DFAState();
//    auto dfa_5 = new DFAState();
//
//    dfa_0->word = "q0";
//    dfa_1->word = "q1";
//    dfa_2->word = "q2";
//    dfa_3->word = "q3";
//    dfa_4->word = "q4";
//    dfa_5->word = "q5";
//
//    dfa_0->setPath('f', dfa_1);
//    dfa_1->setPath('e', dfa_2);
//    dfa_1->setPath('i', dfa_4);
//    dfa_2->setPath('e', dfa_3);
//    dfa_4->setPath('e', dfa_5);
//
//    dfa_3->setEnd();
//    dfa_5->setEnd();
//
//    auto dfa = DFA();
//    dfa.setStartState(dfa_0);
//    auto mini = MinimizeDFA::Hopcroft(dfa);



}

TEST(TestDFA, success4) {
    std::string expr = "(fee)|(fie)";
//    std::string expr = "a|b";
    deleteAllMark(expr, " ");
    auto e = NFA::insertExplicitConcatOperator(expr);
    auto te = NFA::m_to_b(e);
    LOG(INFO) << te;
}

TEST(TestDFA, success5) {
    std::string expr = "(ab|cd)*";
//    std::string expr = "a|b";
    deleteAllMark(expr, " ");
    auto e = NFA::insertExplicitConcatOperator(expr);
    auto te = NFA::m_to_b(e);
    LOG(INFO) << te;
}

