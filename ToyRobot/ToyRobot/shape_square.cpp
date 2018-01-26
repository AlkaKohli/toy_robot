#include "stdafx.h"
#include "shape_square.h"


shape_square::shape_square()
{
	this->m_length = DEFAULT_SIZE;
}

shape_square::shape_square(float length)
{
	m_length = length;
}


shape_square::~shape_square()
{

}


void shape_square::rotate_shape()
{

}

void shape_square::draw_shape()
{

}

float shape_square::get_Dimensions()
{
	return m_length;
}

bool shape_square::is_valid_position(float xpos, float ypos)
{
	if (xpos > 0 && xpos <= this->m_length && ypos > 0 && ypos <= this->m_length)
		return true;

	return false;
}