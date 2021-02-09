//
// Created by tao on 2021/2/5.
//

#ifndef RETEST_TABLEDRIVENSCANNER_H
#define RETEST_TABLEDRIVENSCANNER_H

#include <string>
#include "Lexeme.h"
#include "DFA.h"

namespace Lexer
{
	class TableDrivenScanner
	{
	private:
		std::map<DFAState*, std::map<char, DFAState*>> table;
		DFAState* move(DFAState* state, char path);
		DFAState* getStartState();
		DFA initialDFA;
	public:
		explicit TableDrivenScanner(DFA dfa);
		Lexeme::Token nextToken();
	};

}


#endif //RETEST_TABLEDRIVENSCANNER_H
