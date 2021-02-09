//
// Created by tao on 2021/2/9.
//

#include "Lexicon.h"

void Lexer::Lexicon::defineRulesWithDefault()
{
	this->addKeyWord("if");
	this->addKeyWord("else");
	this->addKeyWord("true");
	this->addKeyWord("false");

	auto d = DFA(this->nfa);
	auto minimizer = MinimizeDFA::Hopcroft();
	auto miniDFA = minimizer.minimize(d);
	this->dfa = miniDFA;
}

void Lexer::Lexicon::addKeyWord(std::string keyword)
{
	std::string keyWord(std::move(keyword));
	auto _nfa = NFA::build(keyWord);
	this->add(_nfa);
}

void Lexer::Lexicon::add(NFA n)
{
	if (this->nfa.getStartState() == nullptr)
	{
		this->nfa = n;
	}
	else
	{
		this->nfa = NFA::createAlternatives(this->nfa, n);
	}
}

DFA Lexer::Lexicon::getDFA()
{
	return this->dfa;
}
