#pragma once
#include "Colors.h"
#include "Vertex.h"

struct Point {
	int x;
	int y;
	Color color;

	Point(int x, int y, Color c) {
		this->x = x;
		this->y = y;
		this->color = c;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
		this->color = White;
	}
	Point(Color c) {
		this->x = 0;
		this->y = 0;
		this->color = c;
	}
	Point(Vertex v, Color c) {
		this->x = v.x;
		this->y = v.y;
		this->color = c;
	}
	Point(Vertex v) {
		this->x = v.x;
		this->y = v.y;
		this->color = White;
	}
	Point() {
		this->x = 0;
		this->y = 0;
		this->color = 0;
	}
};
