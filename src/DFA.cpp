//
// Created by tao on 2021/1/14.
//

#include <algorithm>
#include "DFA.h"

DFA::DFA(NFA nfa)
{
	auto state = nfa.getStartState();
	auto q0 = new DFAState(DFA::epsClosure(state));
	this->startState = q0;
	std::set<DFAState*> Q{};
	Q.insert(q0);
	std::queue<DFAState*> workList{};
	workList.push(q0);

//    auto Alphabet = ;

	while (!workList.empty())
	{
		auto q = workList.front();
		workList.pop();
		for (char c : Define::Alphabet)
		{
			auto states = DFA::epsClosure(DFA::move(q->getNFAStates(), c));
			if (states.empty())
				continue;
			auto existedDFAState = DFA::getDFAState(Q, states);
			if (existedDFAState.has_value())
			{
				auto s = existedDFAState.value();
				q->setPath(c, s);
			}
			else
			{
				auto newQ = new DFAState(states);
				q->setPath(c, newQ);
				Q.insert(newQ);
				workList.push(newQ);
			}
		}
	}
}


/*
 * eps_closure 的无递归版本，先注释了吧，没必要
 * */
//std::vector<NFAState *> DFA::eps_closure(NFAState *state) {
//    auto res = std::vector<NFAState *>();
//    std::set<NFAState* > visited;
//    std::stack<NFAState* > _stack;
//    _stack.push(state);
//    while (!_stack.empty()) {
//        auto s = _stack.top();
//        _stack.pop();
//        for (auto iter = state->epsilonTransition.rbegin(); iter != state->epsilonTransition.rend(); ++iter)
//        {
//            if (visited.count(*iter) == 0) {
//                _stack.push(*iter);;
//            }
//        }
//        visited.insert(s);
//        res.push_back(s);
//    }
//    return res;
//}

/*
 * eps_closure 的递归版本，用这个
 *      目标是输入一个state，能够找到所有不消耗char能到达的边，就是ε边
 * */
void DFA::epsClosure(NFAState* state, std::set<NFAState*>& container)
{
	if (container.count(state))
		return;
	container.insert(state);
	for (auto s : state->epsilonTransition)
	{
		epsClosure(s, container);
	}
}

std::vector<NFAState*> DFA::epsClosure(const std::vector<NFAState*>& T)
{
	auto res = std::set<NFAState*>{};

	for (auto s : T)
	{
		DFA::epsClosure(s, res);
	}

	return std::vector<NFAState*>(res.begin(), res.end());
}

std::vector<NFAState*> DFA::move(const std::vector<NFAState*>& T, char c)
{
	auto res = std::set<NFAState*>{};
	for (auto s : T)
	{
		if (s->existPath(c))
		{
			auto p = s->path(c);
			if (!res.count(p))
			{
				res.insert(p);
			}
		}
	}
	return std::vector<NFAState*>(res.begin(), res.end());
}

std::vector<NFAState*> DFA::epsClosure(NFAState* state)
{
	auto container = std::set<NFAState*>{};
	DFA::epsClosure(state, container);
	return std::vector<NFAState*>(container.begin(), container.end());
}

bool DFA::containStates(const std::set<DFAState*>& Q, const std::vector<NFAState*>& states)
{
	std::set<int> _statesIdSet{};
	std::for_each(states.begin(), states.end(), [&_statesIdSet](auto item)
	{ _statesIdSet.insert((item->id)); });

	for (auto q : Q)
	{
		auto qs = q->getNFAStates();
		std::set<int> _qsIdSet{};
		std::for_each(qs.begin(), qs.end(), [&_qsIdSet](auto item)
		{ _qsIdSet.insert((item->id)); });
		if (_qsIdSet == _statesIdSet)
		{
			return true;
		}
	}
	return false;
}

std::optional<DFAState*> DFA::getDFAState(const std::set<DFAState*>& Q, const std::vector<NFAState*>& states)
{
	std::set<int> _statesIdSet{};
	std::for_each(states.begin(), states.end(), [&_statesIdSet](auto item)
	{ _statesIdSet.insert((item->id)); });

	for (auto q : Q)
	{
		auto qs = q->getNFAStates();
		std::set<int> _qsIdSet{};
		std::for_each(qs.begin(), qs.end(), [&_qsIdSet](auto item)
		{ _qsIdSet.insert((item->id)); });
		if (_qsIdSet == _statesIdSet)
		{
			return q;
		}
	}
	return std::nullopt;;
}

DFAState* DFA::getStartState()
{
	return this->startState;
}

std::vector<DFAState*> DFA::getAllStates()
{
	std::queue<DFAState*> _queue;
	_queue.push(this->getStartState());
	std::set<DFAState*> visited;
	visited.insert(this->getStartState());

	while (!_queue.empty())
	{
		auto front = _queue.front();
		_queue.pop();
		for (auto&[_, value] : front->getAllPath())
		{
			if (!visited.count(value))
			{
				visited.insert(value);
				_queue.push(value);
			}
		}
	}

	return std::vector<DFAState*>{ visited.begin(), visited.end() };
}


