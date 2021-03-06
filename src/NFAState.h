//
// Created by tao on 2021/1/7.
//

#ifndef RE_STATE_H
#define RE_STATE_H

#include <map>
#include <vector>
#include "Token.h"
#include <glog/logging.h>

static int StateCount = 0;

namespace NFA
{
	class NFAState
	{
	public:
		int id;
		bool isEnd;
		std::map<char, NFAState*> transition;
		std::vector<NFAState*> epsilonTransition;

		explicit NFAState(bool isEnd = false);
		void addTransition(char token, NFAState* to);
		void addEpsilonTransition(NFAState* to);
		void setEndStatus(bool status);
		[[nodiscard]] bool existPath(char path) const;
		[[nodiscard]] int epsilonTransitionSize() const;
		[[nodiscard]] int transitionSize() const;
		[[nodiscard]] NFAState* path(char c) const;
	};
}


#endif //RE_STATE_H
