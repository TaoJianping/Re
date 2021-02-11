//
// Created by tao on 2021/1/19.
//

#include <utility>
#include "DFAState.h"

std::vector<NFA::NFAState*> DFAState::getNFAStates()
{
	return this->NFAStates;
}

bool DFAState::setPath(char c, DFAState* state)
{
	this->transition[c] = state;
	return true;
}

bool DFAState::containsPath(char c)
{
	return this->transition.count(c) != 0;
}

DFAState* DFAState::pathTo(char c)
{
	return this->transition.at(c);
}

bool DFAState::End() const
{
	return this->status == DFAStateType::Accept;
}

std::map<char, DFAState*> DFAState::getAllPath()
{
	return this->transition;
}

const std::string& DFAState::desc()
{
	return this->description;
}

void DFAState::setDesc(std::string d)
{
	this->description = std::move(d);
}

bool DFAState::accept() const
{
	return this->status == DFAStateType::Accept;
}

DFAState::DFAState(std::vector<NFA::NFAState*> states) : NFAStates(std::move(states))
{
	for (auto s : NFAStates)
	{
		if (s->isEnd)
		{
			this->status = DFAStateType::Accept;
			break;
		}
	}
}

void DFAState::setEnd()
{
	this->status = DFAStateType::Accept;
}

DFAState::DFAState(bool isError)
{
	if (isError) {
		this->status = DFAStateType::Error;
	} else {
		this->status = DFAStateType::Normal;
	}
}

bool DFAState::error() const
{
	return this->status == DFAStateType::Error;
};