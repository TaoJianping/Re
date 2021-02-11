//
// Created by tao on 2021/2/5.
//

#ifndef RETEST_TABLEDRIVENSCANNER_H
#define RETEST_TABLEDRIVENSCANNER_H

#include <string>
#include "Lexeme.h"
#include "MinimizeDFA.h"
#include <stack>
#include <fstream>
#include "Utils.h"

namespace Lexer
{
	class TableDrivenScanner
	{
	private:
		std::map<DFAState*, std::map<char, DFAState*>> table;
		DFAState* move(DFAState* state, char path);
		DFAState* getStartState();
		DFA initialDFA;
		Utils::TextReader input;

	public:
		explicit TableDrivenScanner(DFA dfa);
		void read(const std::string& filePath);
		Lexeme::Token nextToken();
		bool end();
	};

}


#endif //RETEST_TABLEDRIVENSCANNER_H
