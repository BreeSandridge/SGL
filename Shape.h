#pragma once
#include <Windows.h>
#include <vector>
#include <bitset> 
#include <string>


class RectangleShape;
class Circle;

enum type { polygon = 0, rectangle = 1, circle = 2 };

class Shape {
public:
	int shapeType;
	

	std::vector<POINT> vertices;

	Shape();
	Shape (const RectangleShape& rect);
	
	POINT* get_points();
	int get_size() const;

	RectangleShape to_rect();
	Circle to_circle();
};


class Circle : public Shape {
private:
	const unsigned int top_right_ = 1;
	const unsigned int bot_left_ = 0;


	
public:
	const unsigned int bot = 0;
	const unsigned int top = 1;
	const unsigned int left = 2;
	const unsigned int right = 3;
	
	Circle(POINT bot_left, POINT top_right);
	POINT get_top_right();
	POINT get_bot_left();
	POINT* get_points();
	int* get_point_data();

	void set_bot_left(int x, int y);
	void set_top_right(int x, int y);
	void set_rect(int bot_left_x, int bot_left_y, int top_right_x, int top_right_y);

	void set_bot_left(POINT point);
	void set_top_right(POINT point);
	void set_rect(POINT bot_left, POINT top_right);


	void set_bot_left_x(int x);
	void set_top_right_x(int x);

	void set_bot_left_y(int y);
	void set_top_right_y(int y);


	int get_bot_left_x();
	int get_top_right_x();

	int get_bot_left_y();
	int get_top_right_y();
};

class RectangleShape : public Shape {
private:
	const bool botLeftI = 0;
	const bool topRightI = 1;
public:
	RectangleShape(POINT bot_left, POINT top_right);
	POINT get_top_right();
	POINT get_bot_left();
	POINT* get_points();
	int* get_point_data();

	void set_bot_left(int x, int y);
	void set_top_right(int x, int y);
	void set_rect(int bot_left_x, int bot_left_y, int top_right_x, int top_right_y);

	void set_bot_left(POINT point);
	void setTopRight(POINT point);
	void set_rect(POINT bot_left, POINT top_right);


	void set_bot_left_x(int x);
	void set_top_right_x(int x);

	void set_bot_left_y(int y);
	void set_top_right_y(int y);


	int get_bot_left_x();
	int get_top_right_x();

	int get_bot_left_y();
	int get_top_right_y();
};