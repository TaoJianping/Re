//
// Created by tao on 2021/1/19.
//

#ifndef RETEST_DFASTATE_H
#define RETEST_DFASTATE_H
#include <utility>
#include <vector>
#include "NFAState.h"

class DFAState
{
	enum class DFAStateType
	{
		Normal,
		Accept,
		Error,
	};
private:
	std::vector<NFA::NFAState*> NFAStates{};
	std::map<char, DFAState*> transition{};
	std::string description{};
	DFAStateType status = DFAStateType::Normal;
public:
	const std::string& desc();
	void setDesc(std::string d);
	explicit DFAState(std::vector<NFA::NFAState*> states);
	DFAState() = default;
	explicit DFAState(bool isError);
	std::vector<NFA::NFAState*> getNFAStates();
	bool setPath(char c, DFAState* state);
	bool containsPath(char c);
	DFAState* pathTo(char c);
	[[nodiscard]] bool End() const;
	[[nodiscard]] bool accept() const;
	[[nodiscard]] bool error() const;
	std::map<char, DFAState*> getAllPath();
	void setEnd();
};


#endif //RETEST_DFASTATE_H
