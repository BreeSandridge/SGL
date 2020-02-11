#include "Shape.h"

Shape::Shape() {
	shapeType = polygon;

	vertices = std::vector<POINT>();
}

Shape::Shape(const RectangleShape& rect) {
	shapeType = rect.shapeType;
	vertices = rect.vertices;
}

POINT* Shape::getPoints() {
	auto* points = new POINT [vertices.size()];

	for (int i = 0; i < vertices.size(); i++) {
		points[i] = vertices[i];
	}

	return points;
}


int Shape::get_size() const {
	return vertices.size();
}

RectangleShape Shape::to_rect() {
	return {vertices[0], vertices[1]};
}



RectangleShape::RectangleShape(const POINT bot_left, const POINT top_right) {
	shapeType = rectangle;
	vertices.push_back(bot_left);
	vertices.push_back(top_right);
}

POINT RectangleShape::get_top_right() {
	return vertices[topRightI];
}

POINT RectangleShape::get_bot_left() {
	return vertices[botLeftI];
}

POINT* RectangleShape::get_points() {
	auto* p = new POINT[2];
	p[0] = get_bot_left();
	p[1] = get_top_right();
	return p;
}

int* RectangleShape::get_point_data() {
	const auto p = new int[4];
	p[0] = get_bot_left().x;
	p[1] = get_bot_left().y;
	p[2] = get_top_right().x;
	p[3] = get_top_right().y;
	return p;
}

void RectangleShape::set_bot_left(const int x, const int y) {
	vertices[botLeftI].x = x;
	vertices[botLeftI].y = y;
}

void RectangleShape::set_top_right(const int x, const int y) {
	vertices[topRightI].x = x;
	vertices[topRightI].y = y;
}

void RectangleShape::set_rect(const int bot_left_x, const int bot_left_y, const int top_right_x, const int top_right_y) {
	vertices[botLeftI].x = bot_left_x;
	vertices[botLeftI].y = bot_left_y;

	vertices[topRightI].x = top_right_x;
	vertices[topRightI].y = top_right_y;
}

void RectangleShape::set_bot_left(const POINT point) {
	vertices[botLeftI] = point;
}

void RectangleShape::setTopRight(const POINT point) {
	vertices[topRightI] = point;
}

void RectangleShape::set_rect(const POINT bot_left, const POINT top_right) {
	vertices[botLeftI] = bot_left;
	vertices[topRightI] = top_right;
}

void RectangleShape::set_bot_left_x(const int x) {
	vertices[botLeftI].x = x;
}

void RectangleShape::set_top_right_x(const int x) {
	vertices[topRightI].x = x;
}

void RectangleShape::set_bot_left_y(const int y) {
	vertices[botLeftI].y = y;
}

void RectangleShape::set_top_right_y(const int y) {
	vertices[topRightI].y = y;
}

int RectangleShape::get_bot_left_x() {
	return vertices[botLeftI].x;
}

int RectangleShape::get_top_right_x() {
	return vertices[topRightI].x;
}

int RectangleShape::get_bot_left_y() {
	return vertices[botLeftI].y;
}

int RectangleShape::get_top_right_y()
{
	return vertices[topRightI].y;
}

Circle::Circle(const POINT bot_left, const POINT top_right) {
	shapeType = circle;
	vertices.push_back(bot_left);
	vertices.push_back(top_right);
}

POINT Circle::get_top_right() {
	return vertices[TopRight];
}

POINT Circle::get_bot_left() {
	return vertices[BotLeft];
}

POINT* Circle::get_points() {
	auto* p = new POINT[2];
	p[0] = get_bot_left();
	p[1] = get_top_right();
	return p;
}

int* Circle::get_point_data() {
	const auto p = new int[4];
	p[0] = get_bot_left().y;
	p[2] = get_bot_left().x;
	p[3] = get_top_right().x;
	p[1] = get_top_right().y;
	return p;


}

void Circle::set_bot_left(const int x, const int y) {
	vertices[BotLeft].x = x;
	vertices[BotLeft].y = y;
}

void Circle::set_top_right(const int x, const int y) {
	vertices[TopRight].x = x;
	vertices[TopRight].y = y;
}

void Circle::set_rect(const int bot_left_x, const int bot_left_y, const int top_right_x, const int top_right_y) {
	vertices[BotLeft] = { bot_left_x, bot_left_y };
	vertices[TopRight] = { top_right_x, top_right_y };
}

void Circle::set_bot_left(POINT point) {
	vertices[BotLeft] = point;
}

void Circle::set_top_right(POINT point) {
	vertices[TopRight] = point;
}











