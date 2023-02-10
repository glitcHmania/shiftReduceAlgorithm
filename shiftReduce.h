#pragma once
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;

void CreateTable(string table[12][6])
{
	//second column:
	// 0-> id 
	// 1-> + 
	// 2-> * 
	// 3-> ( 
	// 4-> ) 
	// 5-> $

	table[0][3] = "S4";
	table[4][3] = "S4";
	table[6][3] = "S4";
	table[7][3] = "S4";
	table[0][0] = "S5";
	table[4][0] = "S5";
	table[6][0] = "S5";
	table[7][0] = "S5";
	table[1][1] = "S6";
	table[8][1] = "S6";
	table[2][2] = "S7";
	table[9][2] = "S7";
	table[8][4] = "S11";

	table[9][1] = "R1";
	table[9][4] = "R1";
	table[9][5] = "R1";
	table[2][1] = "R2";
	table[2][4] = "R2";
	table[2][5] = "R2";
	table[10][1] = "R3";
	table[10][2] = "R3";
	table[10][4] = "R3";
	table[10][5] = "R3";
	table[3][1] = "R4";
	table[3][2] = "R4";
	table[3][4] = "R4";
	table[3][5] = "R4";
	table[11][1] = "R5";
	table[11][2] = "R5";
	table[11][4] = "R5";
	table[11][5] = "R5";
	table[5][1] = "R6";
	table[5][2] = "R6";
	table[5][4] = "R6";
	table[5][5] = "R6";

	table[1][5] = "accept";
}
class srMap
{
public:
	srMap()
	{
		stack.push("0");
		goTo[0][0] = "1";
		goTo[0][1] = "2";
		goTo[0][2] = "3";
		goTo[4][0] = "8";
		goTo[4][1] = "2";
		goTo[4][2] = "3";
		goTo[6][1] = "9";
		goTo[6][2] = "3";
		goTo[7][2] = "10";
	}
	void Shift(char input, int num)
	{
		string tempInput, tempNum;
		tempInput.push_back(input);
		tempNum.push_back('0' + num);
		stack.push(tempInput);
		stack.push(tempNum);
	}
	int PeekStack()
	{
		if (stack.top()[1] != NULL)
		{
			return ((stack.top())[0] - 48) * 10 + ((stack.top())[1] - 48);
		}
		return (stack.top())[0] - 48;
	}
	void Reduce(int num)
	{
		int tempIndex;
		switch (num)
		{
		case 1:
			for (int i = 0; i < 6; i++) {
				stack.pop();}
			if (stack.top()[1]!=NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("E");
			stack.push(goTo[tempIndex][0]);
			break;
		case 2:
			for (int i = 0; i < 2; i++) {
				stack.pop();}
			if (stack.top()[1] != NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("E");
			stack.push(goTo[tempIndex][0]);
			break;
		case 3:
			for (int i = 0; i < 6; i++) {
				stack.pop();}
			if (stack.top()[1] != NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("T");
			stack.push(goTo[tempIndex][1]);
			break;
		case 4:
			for (int i = 0; i < 2; i++) {
				stack.pop();}
			if (stack.top()[1] != NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("T");
			stack.push(goTo[tempIndex][1]);
			break;
		case 5:
			for (int i = 0; i < 6; i++){
				stack.pop();}
			if (stack.top()[1] != NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("F");
			stack.push(goTo[tempIndex][2]);
			break;
		case 6:
			for (int i = 0; i < 2; i++){
				stack.pop();}
			if (stack.top()[1] != NULL)
			{
				tempIndex = ((stack.top()[0] - 48) * 10 + (stack.top()[1] - 48));
			}
			else
			{
				tempIndex = (stack.top()[0] - 48);
			}
			stack.push("F");
			stack.push(goTo[tempIndex][2]);
			break;
		}
	}
private:
	stack<string> stack;
	string goTo[12][3];
};