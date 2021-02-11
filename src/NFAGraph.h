//
// Created by tao on 2021/1/8.
//

#ifndef RE_NFAGRAPH_H
#define RE_NFAGRAPH_H

#include <cctype>
#include "NFAState.h"
#include <stack>

namespace NFA
{
	std::string insertExplicitConcatOperator(const std::string& exp);

	std::string m_to_b(const std::string& expr);

	class NFAGraph
	{
	private:
		NFAState* startState;
		NFAState* endState;
	public:
		NFAGraph(NFAState* start, NFAState* end);
		NFAGraph();
		static NFAGraph build(const std::string& expr);
		NFAState* getStartState();
		static NFAGraph createBasicNFA(char c);
		static NFAGraph createConcatenation(NFAGraph former, NFAGraph back);
		static NFAGraph createAlternatives(NFAGraph former, NFAGraph back);
		static NFAGraph createRepetition(NFAGraph nfa);
	};
}



#endif //RE_NFAGRAPH_H
