//
// Created by tao on 2021/2/5.
//

#include <fstream>
#include "TableDrivenScanner.h"


Lexeme::Token Lexer::TableDrivenScanner::nextToken()
{
	std::string lexeme;
	DFAState* state = this->getStartState();
	std::stack<DFAState*> _stack;

	while (!state->error())
	{
		if (this->input.eof())
		{
			break;
		}

		char c = this->input.nextChar();
		lexeme.push_back(c);
		if (state->accept())
		{
			_stack = std::stack<DFAState*>{};
		}
		_stack.push(state);
		state = this->move(state, c);
	}

	while (!state->accept())
	{
		state = _stack.top();
		lexeme.pop_back();
		_stack.pop();
		this->input.rollBack();
	};

	return Lexeme::Token(lexeme);
}

Lexer::TableDrivenScanner::TableDrivenScanner(DFA dfa)
{
	this->initialDFA = dfa;
	auto states = dfa.getAllStates();
	for (const auto& state : states)
	{
		for (auto[key, value] : state->getAllPath())
		{
			this->table[state][key] = value;
		}
	}
	this->input = Utils::TextReader();
}

DFAState* Lexer::TableDrivenScanner::move(DFAState* state, char path)
{
	static auto errorState = new DFAState(true);
	if (this->table.count(state) == 0)
	{
		return errorState;
	}
	auto _map = this->table.at(state);
	if (_map.count(path) == 0)
	{
		return errorState;
	}

	return _map.at(path);
}

DFAState* Lexer::TableDrivenScanner::getStartState()
{
	return this->initialDFA.getStartState();
}

void Lexer::TableDrivenScanner::read(const std::string& filePath)
{
	std::ifstream in(filePath);
	std::ostringstream tmp;
	tmp << in.rdbuf();
	std::string str = tmp.str();
//	std::ifstream t(filePath);
//	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	this->input.feed(str);
}

bool Lexer::TableDrivenScanner::end()
{
	return this->input.eof();
}

