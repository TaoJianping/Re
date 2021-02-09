//
// Created by tao on 2021/1/7.
//

#include "NFAState.h"


void NFAState::addEpsilonTransition(NFAState* to)
{
	this->epsilonTransition.push_back(to);
}

void NFAState::addTransition(char token, NFAState* to)
{
	this->transition[token] = to;
}

void NFAState::setEndStatus(bool status)
{
	this->isEnd = status;
}

bool NFAState::existPath(char path) const
{
	return this->transition.count(path) > 0;
}

int NFAState::epsilonTransitionSize() const
{
	return this->epsilonTransition.size();
}

int NFAState::transitionSize() const
{
	return this->transition.size();
}

NFAState* NFAState::path(char c) const
{
	return this->transition.at(c);
}
