// Oregon Institute of Technology
// Instructor: Pete Myers
// CST 229 Grammars
// Fall 2020
// 
//Ruby Felton
//
//Note: project was worked on collaboratively as a class
//
// cst229Ass2RubyFelton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DFA.h"

int main()
{
	//read input file

	//read input and skip comment
	std::string line;
	std::getline(std::cin, line);
	std::cout << "coment: " << line << std::endl;

	//read num states
	std::getline(std::cin, line);
	int nStates = atoi(line.c_str());
	std::cout << "nStates: " << nStates << std::endl;

	//construct state machine
	DFA dfa(nStates);

	//get list of transitions
	std::getline(std::cin, line);
	while (line[0] != 'F')
	{
		char fromeState = line[0];
		char inputChar = line[3];
		char toState = line[6];

		//ad states and trantion to DFA
		dfa.AddState(fromeState);
		dfa.AddState(toState);
		dfa.AddTransition(fromeState, inputChar, toState);
		std::cout << "Transition: " << line << std::endl;
		std::getline(std::cin, line);
	}
	
	//get final states

	for (int i = 3; i < line.length(); i ++)
	{
		//save state
		if(line[i] >= 'A' && line[i] <='Z')
		{
			char finalState = line[i];
			dfa.SetFinalState(finalState);
			std::cout << "final state..." << line[i] << std::endl;
		}
	}
	
	//get list of strings to process

	//process each sting, print accept/reject

	 while (!std::cin.eof())
	 {
		 std::getline(std::cin, line);
	 	
		 // determine if machine accepts or not
		std::cout << "input string..." << line << std::endl;
		// std::string	inputString;
	
		if (dfa.Accept(line))
		{
			std::cout << "accept";
		}
		else
		{
			std::cout << "reject";
		}
		std::cout << "\t" << line << std::endl;
	}

	return 0;
}
