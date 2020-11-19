// Oregon Institute of Technology
// Instructor: Pete Myers
// CST 229 Grammars
// Fall 2020
// 
//Ruby Felton
//
//Note: project was worked on collaboratively as a class
//

#include "DFA.h"

class DFAState
{
public:
	char name;
	std::map<char, DFAState*> transitions;
	bool isFinal;

	DFAState(char name) : name(name), isFinal(false){}

	void AddTransition(char inputChar, DFAState* nextState)
	{
		transitions.emplace(inputChar, nextState);
	}

	DFAState* Transition(char inputChar)
	{
		
		auto iter = transitions.find(inputChar);
		if(iter == transitions.end())
		{
			return nullptr;
		}else
		{
			return iter->second;
		}
	}
};

DFA::DFA(int nStates) : initialState(nullptr)
{
	//ignor nStates for this implimentation
}

void DFA::AddState(char stateName)
{
	if(FindState(stateName) == nullptr)
	{
		DFAState* state = new DFAState(stateName);
		states.emplace(stateName, state);

		if(initialState == nullptr)
		{
			initialState = state;
		}
	}
}

void DFA::AddTransition(char currentState, char inputChar, char nextState)
{
	DFAState* current = FindState(currentState);
	DFAState* next = FindState(nextState);

	current->AddTransition(inputChar, next);
}

bool DFA::Accept(const std::string& s) const
{
	//start with initial state
	DFAState* currentState = initialState;

	//check each input
	for(int i = 0; i < s.length(); i++)
	{
		char inputChar = s[i];

		//try to transition from current state for input char
		DFAState* nextState = currentState->Transition(inputChar);
		
		if(nextState == nullptr)
		{
			//no next state exist reject
			return false;
		}
		else
		{
			//found, set current state to next state
			currentState = nextState;
		}
	}
	//accept/reject based on whether the current state is final or not
	return currentState->isFinal;
}

void DFA::SetInitialState(char stateName)
{
	initialState = FindState(stateName);
}

void DFA::SetFinalState(char stateName)
{
	DFAState* state = FindState(stateName);

	state->isFinal = true;
}

DFAState* DFA::FindState(char stateName)
{
	auto iter = states.find(stateName);

	if(iter == states.end())
	{
		return nullptr;
	}else
	{
		return iter->second;
	}
}
