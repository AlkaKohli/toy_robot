#include "stdafx.h"
#include <iostream>

using namespace std;

#include "robot_simulator.h"

#define STEP_SIZE 1
#define ROTATION_ANGLE 90
#define stringval( name ) # name

const char* enDirectionNames[] =
{
	stringval(NORTH),
	stringval(WEST),
	stringval(SOUTH),
	stringval(EAST)
};


robot_simulator::robot_simulator()
{
	m_onTable = false;
	m_x_coordinate = -1;
	m_y_coordinate = -1;
	m_facing_direction = robot_simulator::NORTH;
}

void robot_simulator::set_direction(char facingDirection)
{
	switch (facingDirection)
	{
	case 'n':
	case 'N':
	{
		set_direction(robot_simulator::NORTH);
		break;
	}

	case 's':
	case 'S':
	{
		set_direction(robot_simulator::SOUTH);
		break;
	}

	case 'e':
	case 'E':
	{
		set_direction(robot_simulator::EAST);
		break;
	}

	case 'w':
	case 'W':
	{
		set_direction(robot_simulator::WEST);
		break;
	}

	default:
	{
		cout << "Invalid direction specified: SETTING TO NORTH BY DEFAULT" << endl;
		set_direction(DIRECTION_t::NORTH);
	}

	}
}

robot_simulator::robot_simulator(float xPosition, float yPosition, char facingDirection, bool validPos)
{
	m_onTable = validPos;
	m_x_coordinate = xPosition;
	m_y_coordinate = yPosition;

	set_direction(facingDirection);
}

robot_simulator::~robot_simulator()
{

}

void robot_simulator::set_place(float xPosition, float yPosition, char facingDirection, bool isValidPos)
{
	m_x_coordinate = xPosition;
	m_y_coordinate = yPosition;
	m_onTable = isValidPos;

	set_direction(facingDirection);
}

void robot_simulator::move_robot(float tableLength)
{
	move_robot(tableLength, tableLength);
}


void robot_simulator::move_robot(float tableLength, float tableWidth)
{
	if (m_onTable == true)
	{
		switch (m_facing_direction)
		{
		case DIRECTION_t::EAST:
		{
			if (m_x_coordinate + STEP_SIZE <= tableWidth)
			{
				m_x_coordinate += STEP_SIZE;
			}
			else
				cout << "Invalid move \n";

			break;
		}

		case DIRECTION_t::WEST:
		{
			if (m_x_coordinate - STEP_SIZE > 0)
			{
				m_x_coordinate -= STEP_SIZE;
			}
			else
				cout << "Invalid move \n";

			break;
		}

		case DIRECTION_t::NORTH:
		{
			if (m_y_coordinate + STEP_SIZE <= tableLength)
			{
				m_y_coordinate += STEP_SIZE;
			}
			else
				cout << "Invalid move \n";

			break;
		}

		case DIRECTION_t::SOUTH:
		{
			if (m_y_coordinate - STEP_SIZE > 0)
			{
				m_y_coordinate -= STEP_SIZE;
			}
			else
				cout << "Invalid move \n";

			break;
		}

		default:
			cout << "Incorrect placing \n";
		}
	}
	else
		cout << "NOT ON TABLE " << endl;
}

void robot_simulator::turn(char rotationDirection)
{
	switch (m_facing_direction)
	{
	case DIRECTION_t::NORTH:
	{
		if (rotationDirection == 'l')
			set_direction(DIRECTION_t::WEST);
		else
			set_direction(DIRECTION_t::EAST);

		break;
	}

	case DIRECTION_t::WEST:
	{
		if (rotationDirection == 'l')
			set_direction(DIRECTION_t::SOUTH);
		else
			set_direction(DIRECTION_t::NORTH);
		break;
	}

	case DIRECTION_t::SOUTH:
	{
		if (rotationDirection == 'l')
			set_direction(DIRECTION_t::EAST);
		else
			set_direction(DIRECTION_t::WEST);
		break;
	}

	case DIRECTION_t::EAST:
	{
		if (rotationDirection == 'l')
			set_direction(DIRECTION_t::NORTH);
		else
			set_direction(DIRECTION_t::SOUTH);
		break;
	}

	default:
	{
		cout << "Problem with move" << endl;
	}
	}
}


void robot_simulator::turn_left()
{
	turn('l');
}

void robot_simulator::turn_right()
{
	turn('r');

	/*
	if (m_facing_direction == DIRECTION_t::NORTH)
	m_facing_direction = DIRECTION_t::EAST;
	else
	m_facing_direction = static_cast<DIRECTION_t>((static_cast<int>(m_facing_direction)) - ROTATION_ANGLE);
	*/
}

void robot_simulator::set_direction(DIRECTION_t direction)
{
	m_facing_direction = direction;
}

void robot_simulator::display_report()
{
	//int dirIndex = (static_cast<int> (m_facing_direction)) / ROTATION_ANGLE - 1;
	//cout << enDirectionNames[dirIndex] << endl;
	cout << "The position of the robot is (" << m_x_coordinate << " ," << m_y_coordinate << ") facing ";
	cout << enDirectionNames[m_facing_direction] << endl;
}

bool robot_simulator::is_placed_ontable()
{
	return this->m_onTable;
}


