//
// Created by tao on 2021/1/7.
//

#include "NFAState.h"


void NFA::NFAState::addEpsilonTransition(NFAState* to)
{
	this->epsilonTransition.push_back(to);
}

void NFA::NFAState::addTransition(char token, NFAState* to)
{
	this->transition[token] = to;
}

void NFA::NFAState::setEndStatus(bool status)
{
	this->isEnd = status;
}

bool NFA::NFAState::existPath(char path) const
{
	return this->transition.count(path) > 0;
}

int NFA::NFAState::epsilonTransitionSize() const
{
	return this->epsilonTransition.size();
}

int NFA::NFAState::transitionSize() const
{
	return this->transition.size();
}

NFA::NFAState* NFA::NFAState::path(char c) const
{
	return this->transition.at(c);
}

NFA::NFAState::NFAState(bool isEnd)
	: isEnd(isEnd)
{
	this->id = StateCount++;
}
