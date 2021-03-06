// ToyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <sstream>
#include <iterator>

#include "shape_square.h"
#include "robot_simulator.h"

using namespace std;

//#define MAX_SIZE 100;		// max table size

int main()
{

	//creating the table
	shape_square *ptrTable;
	int squarelength = -1;
	cout << "Enter the square table dimension between 1 and 100 \n";
	cin >> squarelength;

	if ((squarelength > 0) && (squarelength <= 100))
	{
		ptrTable = new shape_square(squarelength);
		cout << "Square table of size " << squarelength << " is created" << endl;
	}
	else
	{
		squarelength = DEFAULT_SIZE;
		ptrTable = new shape_square();
		cout << "\n INVALID VALUE: Square table of default size " << squarelength << " is created" << endl;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	robot_simulator objRobot;
	string strUserCommands = "", cmd = "";

	do
	{
		cout << endl << "Enter all the commands for the Robot:\n" << endl << "PLACE(x-cordinate,y-cordinate,direction) without any spaces - eg PLACE(3,4,S)" << endl << "MOVE" << endl << "LEFT" << endl << "RIGHT" << endl << "REPORT" << endl << "EXIT \n" << endl;
		getline(cin, strUserCommands);

		istringstream streamUserCommands(strUserCommands);
		istream_iterator<string> iteratorUserCommands(streamUserCommands), end;
		vector<string> stringVector_t(iteratorUserCommands, end);	//seperating the commands based on space
		int iNoCmds = stringVector_t.size();

		try
		{

			for (int i = 0; i < iNoCmds; i++)
			{
				try
				{
					cmd = stringVector_t.at(i);
				}

				catch (out_of_range o)
				{
					cout << o.what() << endl;
					break;
				}

				std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);		//converts the cmd in lower case

				if (cmd == "move")
				{
					if (objRobot.is_placed_ontable() == false)
					{
						cout << "ROBOT needs to be placed on table first, call PLACE command " << endl;
					}
					else
					{
						objRobot.move_robot(squarelength);
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
				else if (cmd == "place")	//place with no parameters..empty space in between place command and parameters
				{
					cout << "INCORRECT COMMAND  Place command not given in proper format    " << endl;
				}
				else if (cmd.find("place", 0) != string::npos)
				{
					try
					{
						int xpos = -1, ypos = -1;
						string direction, tempStr1, tempStr2;
						bool posStatus = false;

						try
						{
							tempStr1 = cmd.substr(5, string::npos);					//extract parameters of place cmd, 5 is the length of place command
							tempStr2 = tempStr1.substr(1, tempStr1.length() - 2);   // removing the brackets

							replace(tempStr2.begin(), tempStr2.end(), ',', ' ');	// using space as seperator for input parameters
							istringstream streamPlaceParameters(tempStr2);
							istream_iterator<string> iteratorPlaceParameters(streamPlaceParameters), end;
							vector<string> stringPlaceParaVector_t(iteratorPlaceParameters, end);

							direction = stringPlaceParaVector_t.at(2);			//fetching parameters
							xpos = stoi(stringPlaceParaVector_t.at(0));
							ypos = stoi(stringPlaceParaVector_t.at(1));

						}
						catch (out_of_range o)
						{
							xpos = 0;							//incorrect parameters with place command
							ypos = 0;
							//cout << o.what() << endl;
						}
						catch (const std::invalid_argument& ia)
						{
							xpos = 0;							//incorrect value of x and y
							ypos = 0;
							//std::cerr << "Invalid argument: " << ia.what() << '\n';
						}

						posStatus = ptrTable->is_valid_position(xpos, ypos);
						if (posStatus == false)
						{
							xpos = 1;
							ypos = 1;
							posStatus = true;
							cout << "PLACE command should be in proper format & values should be between 1 and " << squarelength << endl;
						}

						if (direction.length() > 1)
						{
							cout << "\n INVALID ENTRY, suppose to enter E,W,N,S... setting to default direction North";
							objRobot.set_place(xpos, ypos, 'n', posStatus);
						}
						else
						{
							objRobot.set_place(xpos, ypos, direction.at(0), posStatus);
						}
					}
					catch (std::invalid_argument& ia)
					{
						//std::cerr << "Invalid argument: " << ia.what() << '\n';
						cout << "INCORRECT FORMAT OF PLACE COMMAND, IGNORING THIS COMMAND";
					}
				}
				else
				{
					if (cmd != "exit")
					{
						cout << "INCORRECT COMMAND      " << cmd << endl;
					}
				}

				if (i == iNoCmds - 1)
				{
					cout << endl << " *********************ALL COMMANDS EXECUTED SUCCESSFULLY ******************" << endl;
				}
			} // end of for loop
		} //try block
		catch (out_of_range o)
		{
			//cout << o.what() << endl;
		}

	} while (cmd != "exit");

	delete ptrTable;

	return 0;
}

