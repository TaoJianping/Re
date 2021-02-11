//
// Created by tao on 2021/2/5.
//

#include <iostream>
#include "Lexeme.h"

Lexeme::Token::Token(std::string lexeme)
{
	if (lexeme == "if")
	{
		this->type = TokenType::KEYWORDS;
		this->value = TokenValue::IF;
	}
	else if (lexeme == "else")
	{
		this->type = TokenType::KEYWORDS;
		this->value = TokenValue::ELSE;
	}
	else if (lexeme == "true")
	{
		this->type = TokenType::KEYWORDS;
		this->value = TokenValue::TRUE;
	}
	else if (lexeme == "false")
	{
		this->type = TokenType::KEYWORDS;
		this->value = TokenValue::FALSE;
	}
}

void Lexeme::Token::print()
{
	if (this->value == TokenValue::IF)
	{
		std::cout << "Token Value -> IF" << std::endl;
	}
	else if (this->value == TokenValue::ELSE)
	{
		std::cout << "Token Value -> ELSE" << std::endl;
	}
	else if (this->value == TokenValue::TRUE)
	{
		std::cout << "Token Value -> TRUE" << std::endl;
	}
	else if (this->value == TokenValue::FALSE)
	{
		std::cout << "Token Value -> FALSE" << std::endl;
	}
}
