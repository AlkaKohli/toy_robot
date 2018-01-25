// ToyRobot.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>

#include "shape_square.h"

using namespace std;

int main()
{
	//creating the table
	shape_square *ptrTable;
	float squarelength = -1;
	cout << "Enter the square table dimension \n";
	cin >> squarelength;

	if (squarelength <= 0)
	{
		cout << "Invalid: creating default size table \n";
		ptrTable = new shape_square();
	}
	else
		ptrTable = new shape_square(squarelength);


	// check for position at which u want to place robot
	float xpos = -1, ypos = -1;
	cout << "Enter the desired pos \n";
	cin >> xpos >> ypos;

	bool posStatus = ptrTable->is_valid_position(xpos, ypos);
	if (posStatus == true)
		cout << "Valid\n";
	else
		cout << "Invalid\n";

	delete ptrTable;

	return 0;
}

