#pragma once
class shape_base
{
	public:
		shape_base();
		~shape_base();

		virtual void rotate_shape() = 0;
		virtual void draw_shape()	= 0;
};

