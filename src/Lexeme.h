//
// Created by tao on 2021/2/5.
//

#ifndef RETEST_LEXEME_H
#define RETEST_LEXEME_H

#include <string>


namespace Lexeme
{
	enum class TokenType
	{
		// see pascal standard 6.4

		// in fact, we can put these 5 types to one category
		// named constant. but I want to make it cleaner.
		INTEGER,        // such as 3, 4 and so on
		REAL,           // such as 3.14
		BOOLEAN,        // true or false.
		CHAR,           // such as 'a','b'
		STRING_LITERAL, // such as 'hello world'


		IDENTIFIER,     // such as abc
		KEYWORDS,       // such as if
		OPERATORS,      // such as  + - * /
		DELIMITER,      // such as ,
		END_OF_FILE,    // end of file
		UNKNOWN
	};

	enum class TokenValue
	{
		// see pascal standard 6.1.2
		AND,
		FOR,
		TO,
		DOWNTO,
		DO,
		IF,
		THEN,
		ELSE,
		WHILE,
		REPEAT,
		UNTIL,
		FUNCTION,
		PROCEDURE,
		BEGIN,
		END,
		PROGRAM,
		FORWARD,
		GOTO,
		OR,
		NOT,
		CASE,
		OTHERWISE,
		WITH,
		IN,
		TRUE,
		FALSE,

		// I/O routine
		WRITE,
		WRITELN,
		READ,
		READLN,

		// type/var/const
		TYPE,
		VAR,
		PACKED,
		ARRAY,
		OF,
		RECORD,
		CONST,
		FILE,
		SET,
		STRING,
		NIL,

		// symbols
		LEFT_PAREN,        // (
		RIGHT_PAREN,       // )
		LEFT_SQUARE,       // [
		RIGHT_SQUARE,      // ]
		PLUS,              // +
		MINUS,             // -
		MULTIPLY,          // *
		DIVIDE,            // /
		COMMA,             // ,
		SEMICOLON,         // ;
		COLON,             // :
		ASSIGN,            // :=
		PERIOD,            // .
		DOT_DOT,           // ..
		UPARROW,           // ^
		DIV,               // div
		MOD,               // mod
		XOR,               // xor
		SHR,               // shr
		SHL,               // shl

		// comparation symbols
		LESS_OR_EQUAL,     // <=
		LESS_THAN,         // <
		GREATER_OR_EQUAL,  // >=
		GREATER_THAN,      // >
		EQUAL,             // =
		NOT_EQUAL,         // <>

		UNRESERVED
	};

	class Token
	{
	private:
		TokenType type;
		TokenValue value;
	public:
		explicit Token(std::string lexeme);
		void print();
	};

};


#endif //RETEST_LEXEME_H
