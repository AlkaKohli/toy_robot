#pragma once



class robot_simulator
{
public:
	enum DIRECTION_t { NORTH, WEST, SOUTH, EAST };

	robot_simulator();
	robot_simulator(float xPosition, float yPosition, char facingDirection, bool validPos);
	~robot_simulator();


	void set_place(float xPosition, float yPosition, char facingDirection, bool isValidPos);
	void move_robot(float);				//for square shaped table
	void move_robot(float, float);		// for rectangle shaped table

	void turn(char rotationDirection);
	void turn_left();
	void turn_right();

	void set_direction(char facingDirection);
	void set_direction(DIRECTION_t direction);

	void display_report();

	bool is_placed_ontable();

private:
	DIRECTION_t	m_facing_direction;
	float		m_x_coordinate;
	float		m_y_coordinate;
	bool		m_onTable;


};

