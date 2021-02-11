#include <gtest/gtest.h>
#include <glog/logging.h>
#include "TableDrivenScanner.h"
#include "Lexicon.h"

TEST(TestTableGrivenScanner, success)
{
	auto lex = Lexer::Lexicon();
	lex.defineRulesWithDefault();
	auto dfa = lex.getDFA();

	auto scanner = Lexer::TableDrivenScanner(dfa);
	scanner.read("../haha.tpp");
	while (!scanner.end())
	{
		auto token = scanner.nextToken();
		token.print();
	}
}