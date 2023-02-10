#include "shiftReduce.h"
#include <iostream>
using namespace std;

//second column:
	// 0-> id 
	// 1-> + 
	// 2-> * 
	// 3-> ( 
	// 4-> ) 
	// 5-> $

int main()
{
	srMap srMap;
	string table[12][6];
	CreateTable(table);
	string input;
	cout << "Enter your string:" << endl;
	cin >> input;
	input.push_back('$');
	bool invalidFlag = false;
	for (int i = 0; input[i] != NULL && !invalidFlag; i++)
	{
		bool onRepeat = true;
		while(onRepeat)
		{
			string action;
			int tempIndex;
			tempIndex = srMap.PeekStack();
			switch (input[i])
			{
			case 'i':
				if(input[i+1] == 'd')
				{
					action = table[tempIndex][0];
					break;
				}
				break;
			case '+':
				action = table[tempIndex][1];
				break;
			case '*':
				action = table[tempIndex][2];
				break;
			case '(':
				action = table[tempIndex][3];
				break;
			case ')':
				action = table[tempIndex][4];
				break;
			case '$':
				action = table[tempIndex][5];
				break;
			}
			if (action[0] == 'S')
			{
				if(action[2]==NULL)
				{
					srMap.Shift(input[i], action[1] - 48);
				}
				else
				{
					srMap.Shift(input[i], ((action[1]-48)*10+(action[2]-48)));
				}
				onRepeat = false;
			}
			else if (action[0] == 'R')
			{
				srMap.Reduce(action[1] - 48);
			}
			else if (action[0] == 'a')
			{
				cout << "VALID string entered. ACCEPTED!" << endl;
				break;
			}
			else
			{
				onRepeat = false;
				if (input[i] != 'd')
				{
					if(input[i-1] != 'i')
					{
						cout << "INVALID string entered. SYNTAX ERROR!" << endl;
						invalidFlag = true;
						break;
					}
				}
			}
		}
	}
	return 0;
}
