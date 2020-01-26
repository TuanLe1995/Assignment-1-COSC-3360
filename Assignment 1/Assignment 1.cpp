// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>

int main()
{
	int currentProTime = 0;
	int numCore = 0;
	int numFreeCore= 0;
	int numProcess = 0;
	int coreWaitingTime = 0;
	PID_Queue I_QUEUE;
	PID_Queue NI_QUEUE;
	PID_Queue PIDQ;
	char start[10];

	std::cin >> start;
	std::cout << start;
	PIDQ.insert(0, 0);
	PIDQ.insert(1, -1);
	PIDQ.insert(2, 4);

	PID* P0 = PIDQ.DeQueue();
	PID* P1 = PIDQ.DeQueue();
	PID* P2 = PIDQ.DeQueue();
	free(P0);
	free(P1);
	free(P2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
