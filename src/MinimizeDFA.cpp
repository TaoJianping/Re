//
// Created by tao on 2021/1/27.
//

#include "MinimizeDFA.h"


/*
 * 1. 要把所有的states分成Accept和NonAccept的两个集合（MiddleNode）
 * 2. 对每个状态里面的每个state，如果输入的字符不能转换到一样的
 * */
std::vector<MinimizeDFA::MiddleNode> MinimizeDFA::Hopcroft::splitStatesToNA(const std::vector<DFAState*>& states)
{
	MiddleNode AcceptSet{};
	MiddleNode NonAcceptSet{};

	for (auto& state : states)
	{
		if (state->End())
		{
			AcceptSet.states.push_back(state);
		}
		else
		{
			NonAcceptSet.states.push_back(state);
		}
	};

	std::vector<MiddleNode> res{};
	res.push_back(AcceptSet);
	res.push_back(NonAcceptSet);
	return res;
}

std::vector<MinimizeDFA::MiddleNode> MinimizeDFA::Hopcroft::split(const MinimizeDFA::MiddleNode& middleNode,
	std::map<DFAState*, int> _map)
{
	std::map<int, std::vector<DFAState*>> record;

	for (auto c : Define::Alphabet)
	{
		for (auto state : middleNode.states)
		{
			DFAState* path;
			if (state->containsPath(c))
			{
				path = state->pathTo(c);
			}
			else
			{
				path = state;
			}

			auto setNum = _map.at(path);
			record[setNum].push_back(state);
		}
		if (record.size() > 1)
		{
			std::vector<MiddleNode> res;
			for (auto[key, states] : record)
			{
				auto m = MiddleNode();
				m.states = std::move(states);
				res.push_back(m);
			}
			return res;
		}
		else
		{
			record.clear();
		};
	};

	std::vector<MiddleNode> res;
	res.push_back(middleNode);
	return res;
}

DFA MinimizeDFA::Hopcroft::minimize(DFA dfa)
{
	auto states = dfa.getAllStates();
	auto startState = dfa.getStartState();
	std::vector<MiddleNode> P = MinimizeDFA::Hopcroft::splitStatesToNA(states);
	std::map<DFAState*, int> _map;
	for (const auto& p : P)
	{
		for (auto state : p.states)
		{
			_map[state] = p.id;
		}
	}

	bool goOn = true;
	while (goOn)
	{
		decltype(P.begin()) iter;
		std::vector<MiddleNode> resSet{};
		for (iter = P.begin(); iter != P.end(); ++iter)
		{
			if (!iter->splitFinished)
			{
				resSet = MinimizeDFA::Hopcroft::split(*iter, _map);
				if (resSet.size() == 1)
				{
					iter->splitFinished = true;
				}
				else
				{
					break;
				}
			}
		}

		if (iter != P.end())
		{
			P.erase(iter);
			P.insert(iter, resSet.begin(), resSet.end());
			_map.clear();
			for (const auto& p : P)
			{
				for (auto state : p.states)
				{
					_map[state] = p.id;
				}
			}
		}
		if (std::all_of(P.begin(), P.end(), [](const MiddleNode& item)
		{ return item.splitFinished; }))
		{
			goOn = false;
		}
	}

	for (auto& node : P)
	{
		auto res = std::find(node.states.begin(), node.states.end(), startState);
		if (res != node.states.end())
		{
			node.isStart = true;
		}
	}

	auto resDFA = MinimizeDFA::Hopcroft::generate(P);

	return resDFA;
}

DFA MinimizeDFA::Hopcroft::generate(const std::vector<MiddleNode>& P)
{
	std::map<DFAState*, int32_t> record;
	std::map<int32_t, DFAState*> record2;
	DFAState* startState;

	for (const auto& node : P)
	{
		auto d = new DFAState();
		record2[node.id] = d;
		if (node.isStart)
		{
			startState = d;
		}
		for (auto ds : node.states)
		{
			record[ds] = node.id;
		}
	}

	for (const auto& node : P)
	{
		auto dfa = record2[node.id];
		for (const auto& s : node.states)
		{
			if (s->End())
			{
				dfa->setEnd();
			}
			for (auto[path, state] : s->getAllPath())
			{
				dfa->setPath(path, record2.at(record.at(state)));
			}
		}
	}
	if (!startState)
	{
		LOG(ERROR) << "Not found start State!";
		exit(-1);
	}

	auto dfa = DFA();
	dfa.setStartState(startState);
	return dfa;
}
