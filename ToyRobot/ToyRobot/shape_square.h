#pragma once
#include "shape_base.h"

#define DEFAULT_SIZE 5

class shape_square : public shape_base
{
private:
	int m_length;

public:
	shape_square();
	shape_square(int length);
	~shape_square();

	void rotate_shape();
	void draw_shape();

	int get_Dimensions();
	bool is_valid_position(int, int);

};

