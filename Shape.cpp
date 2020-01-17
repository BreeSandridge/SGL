#include "Shape.h"

Shape::Shape() {
	shapeType = polygon;

	vertices = std::vector<POINT>();
}

Shape::Shape(RectangleShape rect) {
	shapeType = rect.shapeType;
	vertices = rect.vertices;
}

POINT* Shape::getPoints() {
	POINT* points = new POINT [vertices.size()];

	for (int i = 0; i < vertices.size(); i++) {
		points[i] = vertices[i];
	}

	return points;
}

int Shape::getSize() {
	return vertices.size();
}

RectangleShape Shape::toRect() {
	return {vertices[0], vertices[1]};
}

RectangleShape::RectangleShape(POINT bot_Left, POINT top_Right) {
	shapeType = rectangle;
	vertices.push_back(bot_Left);
	vertices.push_back(top_Right);
}

POINT RectangleShape::getTopRight() {
	return vertices[topRightI];
}

POINT RectangleShape::getBotLeft() {
	return vertices[botLeftI];
}

POINT* RectangleShape::getPoints() {
	POINT* p = new POINT[2];
	p[0] = getBotLeft();
	p[1] = getTopRight();
	return p;
}

int* RectangleShape::getPointData() {
	int* p = new int[4];
	p[0] = getBotLeft().x;
	p[1] = getBotLeft().y;
	p[2] = getTopRight().x;
	p[3] = getTopRight().y;
	return p;
}

void RectangleShape::setBotLeft(int x, int y) {
	vertices[botLeftI].x = x;
	vertices[botLeftI].y = y;
}

void RectangleShape::setTopRight(int x, int y) {
	vertices[topRightI].x = x;
	vertices[topRightI].y = y;
}

void RectangleShape::setRect(int bot_left_x, int bot_left_y, int top_right_x, int top_right_y) {
	vertices[botLeftI].x = bot_left_x;
	vertices[botLeftI].y = bot_left_y;

	vertices[topRightI].x = top_right_x;
	vertices[topRightI].y = top_right_y;
}

void RectangleShape::setBotLeft(POINT point) {
	vertices[botLeftI] = point;
}

void RectangleShape::setTopRight(POINT point) {
	vertices[topRightI] = point;
}

void RectangleShape::setRect(POINT bot_Left, POINT top_right) {
	vertices[botLeftI] = bot_Left;
	vertices[topRightI] = top_right;
}

void RectangleShape::setBotLeftX(int x) {
	vertices[botLeftI].x = x;
}

void RectangleShape::setTopRightX(int x) {
	vertices[topRightI].x = x;
}

void RectangleShape::setBotLeftY(int y) {
	vertices[botLeftI].y = y;
}

void RectangleShape::setTopRightY(int y) {
	vertices[topRightI].y = y;
}

int RectangleShape::getBotLeftX(int x) {
	return vertices[botLeftI].x;
}

int RectangleShape::getTopRightX(int x) {
	return vertices[topRightI].x = x;
}

int RectangleShape::getBotLeftY(int y) {
	return vertices[botLeftI].y;
}

int RectangleShape::getTopRightY(int y)
{
	return vertices[topRightI].y;
}









