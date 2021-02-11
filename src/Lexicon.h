//
// Created by tao on 2021/2/9.
//

#ifndef RETEST_LEXICON_H
#define RETEST_LEXICON_H
#include "MinimizeDFA.h"

namespace Lexer
{
	class Lexicon
	{
	private:
		NFA::NFAGraph nfa;
		DFA dfa;
		void add(NFA::NFAGraph n);
	public:
//        void defineRules();
		void defineRulesWithDefault();
		void addKeyWord(std::string keyword);
		DFA getDFA();
	};
}


#endif //RETEST_LEXICON_H
