//
// Created by tao on 2021/1/8.
//

#include "NFAGraph.h"
#include "Utils.h"



std::string NFA::insertExplicitConcatOperator(const std::string& exp)
{
	std::string output;

	for (int i = 0; i < exp.length(); ++i)
	{
		const char token = exp[i];
		output += token;

		if (token == (char)Token::GROUP_LEFT_OPERATOR || token == (char)Token::UNION_OPERATOR)
			continue;

		if (i < exp.length() - 1)
		{
			const char lookahead = exp[i + 1];

			if (lookahead == (char)Token::CLOSURE_OPERATOR ||
				lookahead == (char)Token::GROUP_RIGHT_OPERATOR ||
				lookahead == (char)Token::UNION_OPERATOR)
			{
				continue;
			}

			output += (char)Token::CONCATENATION_OPERATOR;
		}
	}
	return output;
}

std::string NFA::m_to_b(const std::string& expr)
{
	LOG(INFO) << "START Shunting Yard Algorithm";
	LOG(INFO) << "EXPR -> " << expr;

	std::stack<char> optStack;
	std::string output;

	for (char c : expr)
	{
		if (c == static_cast<char>(Token::GROUP_LEFT_OPERATOR))
		{
			optStack.push(c);
		}
		else if (isalnum(c))
		{
			output += c;
		}
		else if (c == static_cast<char>(Token::CLOSURE_OPERATOR) ||
			c == static_cast<char>(Token::CONCATENATION_OPERATOR) ||
			c == static_cast<char>(Token::UNION_OPERATOR))
		{
			if (optStack.empty())
			{
				optStack.push(c);
				continue;
			}
			if (optStack.top() == static_cast<char>(Token::GROUP_LEFT_OPERATOR))
			{
				optStack.push(c);
				continue;
			}

			while (!optStack.empty() && OPERATOR_PRIORITY[optStack.top()] > OPERATOR_PRIORITY[c])
			{
				output.push_back(optStack.top());
				optStack.pop();
			}
			optStack.push(c);
		}
		else if (c == static_cast<char>(Token::GROUP_RIGHT_OPERATOR))
		{
			while (optStack.top() != static_cast<char>(Token::GROUP_LEFT_OPERATOR))
			{
				auto i = optStack.top();
				optStack.pop();
				output.push_back(i);
			}
			if (optStack.top() == static_cast<char>(Token::GROUP_LEFT_OPERATOR))
			{
				optStack.pop();
			}
			else
			{
				LOG(ERROR) << "Could Not Find LEFT_OPERATOR";
				exit(-1);
			}
		}
		else
		{
			LOG(ERROR) << "NOT SUPPORT operator or char !";
			exit(-1);
		}
	}

	while (!optStack.empty())
	{
		output += optStack.top();
		optStack.pop();
	}

	LOG(INFO) << "Output -> " << output;
	return output;
}

NFA::NFAGraph NFA::NFAGraph::build(const std::string& originalExpr)
{
	auto expr = m_to_b(insertExplicitConcatOperator(originalExpr));
	std::stack<NFA::NFAGraph> _stack;

	for (char c : expr)
	{
		if (c == '|')
		{
			auto nfaBack = _stack.top();
			_stack.pop();
			auto nfaFormer = _stack.top();
			_stack.pop();
			auto nfa = NFAGraph::createAlternatives(nfaFormer, nfaBack);
			_stack.push(nfa);
		}
		else if (c == '#')
		{
			auto nfaBack = _stack.top();
			_stack.pop();
			auto nfaFormer = _stack.top();
			_stack.pop();
			auto nfa = NFAGraph::createConcatenation(nfaFormer, nfaBack);
			_stack.push(nfa);
		}
		else if (c == '*')
		{
			auto nfa = _stack.top();
			_stack.pop();
			auto n = NFAGraph::createRepetition(nfa);
			_stack.push(n);
		}
		else if (isalpha(c))
		{
			auto nfa = NFAGraph::createBasicNFA(c);
			_stack.push(nfa);
		}
		else
		{
			LOG(ERROR) << "UNSUPPORT CHAR -> " << c;
			throw std::bad_exception();
		}
	}

	return _stack.top();
}

NFA::NFAGraph NFA::NFAGraph::createBasicNFA(char c)
{
	auto start = new NFAState();
	auto end = new NFAState(true);

	start->addTransition(c, end);

	auto nfa = NFAGraph(start, end);
	return nfa;
}

NFA::NFAGraph NFA::NFAGraph::createConcatenation(NFA::NFAGraph former, NFA::NFAGraph back)
{
	former.endState->isEnd = false;
	former.endState->addEpsilonTransition(back.startState);

	auto nfa = NFAGraph(former.startState, back.endState);
	return nfa;
}

NFA::NFAGraph NFA::NFAGraph::createAlternatives(NFA::NFAGraph former, NFA::NFAGraph back)
{
	auto startState = new NFAState();
	auto endState = new NFAState(true);
	former.endState->setEndStatus(false);
	back.endState->setEndStatus(false);

	startState->addEpsilonTransition(former.startState);
	startState->addEpsilonTransition(back.startState);

	former.endState->addEpsilonTransition(endState);
	back.endState->addEpsilonTransition(endState);

	return NFAGraph(startState, endState);
}

NFA::NFAGraph NFA::NFAGraph::createRepetition(NFA::NFAGraph nfa)
{
	auto startState = new NFAState();
	auto endState = new NFAState(true);

	startState->addEpsilonTransition(endState);
	startState->addEpsilonTransition(nfa.startState);
	nfa.endState->setEndStatus(false);
	nfa.endState->addEpsilonTransition(nfa.startState);
	nfa.endState->addEpsilonTransition(endState);

	return NFAGraph(startState, endState);
}

NFA::NFAState* NFA::NFAGraph::getStartState()
{
	return this->startState;
}

NFA::NFAGraph::NFAGraph(NFA::NFAState* start, NFA::NFAState* end): startState(start), endState(end)
{

}

NFA::NFAGraph::NFAGraph(): startState(nullptr), endState(nullptr)
{

}
