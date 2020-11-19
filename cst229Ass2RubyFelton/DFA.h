// Oregon Institute of Technology
// Instructor: Pete Myers
// CST 229 Grammars
// Fall 2020
// 
//Ruby Felton
//
//Note: project was worked on collaboratively as a class
//

#pragma once
#include <string>
#include <map>
class DFAState;

class DFA
{
private:
	std::map<char, DFAState*> states; // state name to state
	DFAState* initialState;

	DFAState* FindState(char stateName);
public:
	DFA(int nStates);

	void AddState(char stateName);

	void AddTransition(char currentState, char inputState, char nextState);

	bool Accept(const std::string& s) const;

	void SetInitialState(char stateName);
	
	void SetFinalState(char stateName);
};
