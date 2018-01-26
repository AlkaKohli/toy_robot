// ToyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

#include "shape_square.h"
#include "robot_simulator.h"

using namespace std;

//#define MAX_SIZE 100;		// max table size

int main()
{

	//creating the table
	shape_square *ptrTable;
	float squarelength = -1;
	cout << "Enter the square table dimension between 1 and 100 \n";
	cin >> squarelength;

	if ((squarelength > 0) && (squarelength <= 100))
		ptrTable = new shape_square(squarelength);

	else
	{
		cout << "Invalid: creating default size table \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		squarelength = DEFAULT_SIZE;
		ptrTable = new shape_square();
	}


	robot_simulator objRobot;
	string cmd;

	do
	{
		cout << endl << "Enter the operation: PLACE, MOVE,LEFT, RIGHT,REPORT or EXIT" << endl;
		cin >> cmd;
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);		//converts the cmd in lower case
		cmd.erase(std::remove(cmd.begin(), cmd.end(), ' '), cmd.end());		//removes trailing white spaces in cmd

		if (cmd == "place")
		{
			float xpos = -1, ypos = -1;
			string direction;
			bool posStatus = false;

			while (true)
			{
				cout << "Enter the desired x and y position";
				cin >> xpos >> ypos;

				posStatus = ptrTable->is_valid_position(xpos, ypos);
				if (posStatus == true)
					break;
				else
				{
					cout << "INCORRECT POSITION: ";
					cout << "The values should be between 1 and " << squarelength << endl;
				}
			}

			cout << endl << "Enter the desired direction:N,S,W,E  ";
			cin >> direction;

			if (direction.length() > 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid entry, suppose to enter E,W,N,S... setting to default north";
				objRobot.set_place(xpos, ypos, 'n', posStatus);
			}
			else
			{
				objRobot.set_place(xpos, ypos, direction.at(0), posStatus);
			}
			//objRobot.display_report();
		}
		else if (cmd == "move")
		{
			if (objRobot.is_placed_ontable() == false)
			{
				cout << "ROBOT needs to be placed on table first, call PLACE command " << endl;
			}
			else
			{
				objRobot.move_robot(squarelength);
				//objRobot.display_report();
			}
		}
		else if (cmd == "right")
		{
			if (objRobot.is_placed_ontable() == false)
			{
				cout << "ROBOT needs to be placed on table first, call PLACE command " << endl;
			}
			else
			{
				objRobot.turn_right();
				//objRobot.display_report();
			}
		}
		else if (cmd == "left")
		{
			if (objRobot.is_placed_ontable() == false)
			{
				cout << "ROBOT needs to be placed on table first, call PLACE command " << endl;
			}
			else
			{
				objRobot.turn_left();
				//objRobot.display_report();
			}
		}
		else if (cmd == "report")
		{
			if (objRobot.is_placed_ontable() == false)
			{
				cout << "ROBOT needs to be placed on table first, call PLACE command " << endl;
			}
			else
			{
				objRobot.display_report();
			}
		}
		else
		{
			if (cmd != "exit")
			{
				cout << "INCORRECT command, retry" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

	} while (cmd != "exit");

	delete ptrTable;

	return 0;
}

