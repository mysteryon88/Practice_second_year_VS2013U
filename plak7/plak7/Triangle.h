#pragma once

class Triangle
{
	float x[3], y[3]; // triangle coordinates
	float a, b, c;    // side of the triangle
	int u1, u2, u3;    // triangle angles

public:
	Triangle(){};
	~Triangle(){};
	bool set_xy_keyboard();
	void set_xy_file();
	bool set_abc();
	void set_angles();
};