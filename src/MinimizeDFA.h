//
// Created by tao on 2021/1/27.
//

#ifndef RETEST_MINIMIZEDFA_H
#define RETEST_MINIMIZEDFA_H

#include "DFA.h"
#include "DFAState.h"
#include <algorithm>
#include "Define.h"

namespace MinimizeDFA
{
	static int MiddleNodeCount = 0;

	struct MiddleNode
	{
		int id = MiddleNodeCount++;
		bool splitFinished = false;
		bool isStart = false;
		std::vector<DFAState*> states;
	};

	class Hopcroft
	{
	public:
		DFA minimize(DFA dfa);
	private:
		static std::vector<MiddleNode> splitStatesToNA(const std::vector<DFAState*>& states);
		static std::vector<MiddleNode> split(const MiddleNode& node, std::map<DFAState*, int> _map);
		static DFA generate(const std::vector<MiddleNode>& P);
	};
}


#endif //RETEST_MINIMIZEDFA_H
