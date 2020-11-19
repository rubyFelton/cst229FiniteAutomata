#pragma once

class DFA2
{
public:
	DFA2(int nStates);

	void AddState(char stateName);

	void AddTransition(char currentState, char inputState, int nextState);

	bool Accept(const std::string s);

	// void Reject(const std::string s);

	void SetInitialState(char stateName);

	void SetFinalState(char stateName);
};
