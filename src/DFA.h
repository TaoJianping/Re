//
// Created by tao on 2021/1/14.
//

#ifndef RETEST_DFA_H
#define RETEST_DFA_H

#include "NFAGraph.h"
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include "NFAState.h"
#include "DFAState.h"
#include "Define.h"

class DFA
{
private:
	static void epsClosure(NFA::NFAState* state, std::set<NFA::NFAState*>& container);
	DFAState* startState;
public:
	explicit DFA(NFA::NFAGraph nfa);
	DFA()
	{
	};
	void setStartState(DFAState* startState)
	{
		this->startState = startState;
	};
	static std::vector<NFA::NFAState*> epsClosure(const std::vector<NFA::NFAState*>& T);
	static std::vector<NFA::NFAState*> epsClosure(NFA::NFAState* state);
	static std::vector<NFA::NFAState*> move(const std::vector<NFA::NFAState*>& T, char c);
	static bool containStates(const std::set<DFAState*>& Q, const std::vector<NFA::NFAState*>& states);
	static std::optional<DFAState*> getDFAState(const std::set<DFAState*>& Q, const std::vector<NFA::NFAState*>& states);
	DFAState* getStartState();
	std::vector<DFAState*> getAllStates();
};


#endif //RETEST_DFA_H
