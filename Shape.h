#pragma once
#include <Windows.h>
#include <vector>
#include <bitset> 
#include <string>


class RectangleShape;

enum type { polygon = 0, rectangle = 1 };

class Shape {
public:
	int shapeType;
	

	std::vector<POINT> vertices;

	Shape();
	Shape (RectangleShape rect);
	
	POINT* getPoints();
	int getSize();

	RectangleShape toRect();
};


class Circle : public Shape {
private:
	std::bitset<2> b1 = std::bitset<2>(2);
	//Research Bitsets
	unsigned int Left : 3;
	unsigned b = 2;
	b << 2;
	const bool Right = 1;
	
	const bool Top = 2;
	const bool Bot = 3;
public:
	Circle(POINT bot_Left, POINT top_Right);
	POINT getTopRight();
	POINT getBotLeft();
	POINT* getPoints();
	int* getPointData();

	void setBotLeft(int x, int y);
	void setTopRight(int x, int y);
	void setRect(int bot_left_x, int bot_left_y, int top_right_x, int top_right_y);

	void setBotLeft(POINT point);
	void setTopRight(POINT point);
	void setRect(POINT bot_Left, POINT top_right);


	void setBotLeftX(int x);
	void setTopRightX(int x);

	void setBotLeftY(int y);
	void setTopRightY(int y);


	int getBotLeftX(int x);
	int getTopRightX(int x);

	int getBotLeftY(int y);
	int getTopRightY(int y);
};

class RectangleShape : public Shape {
private:
	const bool botLeftI = 0;
	const bool topRightI = 1;
public:
	RectangleShape(POINT bot_Left, POINT top_Right);
	POINT getTopRight();
	POINT getBotLeft();
	POINT* getPoints();
	int* getPointData();

	void setBotLeft(int x, int y);
	void setTopRight(int x, int y);
	void setRect(int bot_left_x, int bot_left_y, int top_right_x, int top_right_y);

	void setBotLeft(POINT point);
	void setTopRight(POINT point);
	void setRect(POINT bot_Left, POINT top_right);


	void setBotLeftX(int x);
	void setTopRightX(int x);

	void setBotLeftY(int y);
	void setTopRightY(int y);


	int getBotLeftX(int x);
	int getTopRightX(int x);

	int getBotLeftY(int y);
	int getTopRightY(int y);
};