//
// Created by tao on 2021/1/12.
//

#ifndef RE_UTILS_H
#define RE_UTILS_H

#include <string>
#include <stack>
#include <glog/logging.h>

void deleteAllMark(std::string& s, const std::string& mark);



namespace Utils
{
	class TextReader
	{
	private:
		int32_t column;
		int32_t line;
		std::string text;
	public:
		TextReader();
		void feed(std::string str);
		char nextChar();
		[[nodiscard]] char peek() const;
		char advance();
		bool eof();
		void rollBack();
	};
}


#endif //RE_UTILS_H
