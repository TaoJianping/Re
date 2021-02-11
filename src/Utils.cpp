//
// Created by tao on 2021/1/8.
//


#include "Utils.h"
#include "Token.h"


void deleteAllMark(std::string& s, const std::string& mark)
{
	size_t nSize = mark.size();
	while (true)
	{
		size_t pos = s.find(mark);    //  尤其是这里
		if (pos == std::string::npos)
		{
			return;
		}

		s.erase(pos, nSize);
	}
}


Utils::TextReader::TextReader() : line(1), column(-1)
{

}

char Utils::TextReader::nextChar()
{
	this->column++;
	if (column > this->text.size())
	{
		LOG(ERROR) << "TEXT EXCEED!";
		throw std::exception();
	}
	return this->text.at(this->column);
}

char Utils::TextReader::peek() const
{
	return this->text.at(this->column);
}

char Utils::TextReader::advance()
{
	return this->text.at(this->column++);
}

void Utils::TextReader::feed(std::string str)
{
	this->text = std::move(str);
}

bool Utils::TextReader::eof()
{
	auto a = static_cast<int32_t>(this->text.size());
	return (column + 1) >= static_cast<int32_t>(this->text.size());
}

void Utils::TextReader::rollBack()
{
	this->column--;
}
