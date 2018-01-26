#pragma once
#include "shape_base.h"

#define DEFAULT_SIZE 5

class shape_square : public shape_base
{
	private:
		float m_length;

	public:
		shape_square();
		shape_square(float length);
		~shape_square();

		void rotate_shape();
		void draw_shape();

		float get_Dimensions();
		bool is_valid_position(float, float);

		
};

