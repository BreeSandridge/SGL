#pragma once
#include "Colors.h"
#include "Vertex.h"


#define DEFAULT_LINE_WIDTH = 3;

struct Line {
	Vertex startPt;
	Vertex endPt;
	int thickness;
	Color color;
	
	/*
	Line(Vertex v1, Vertex v2, int thickness, Color c) {
		this->startPt = v1;
		this->endPt = v2;
		this->thickness = thickness;
		this->color = c;
	}
	Line(Vertex v1, Vertex v2, int thickness) {
		this->startPt = v1;
		this->endPt = v2;
		this->thickness = thickness;
		this->color = White;
	}
	Line(Vertex v1, Vertex v2, Color c) {
		this->startPt = v1;
		this->endPt = v2;
		this->thickness = DEFAULT_LINE_WIDTH;
		this->color = c;
	}
	Line(Vertex v1, Vertex v2) {
		this->startPt = v1;
		this->endPt = v2;
		this->thickness = DEFAULT_LINE_WIDTH;
		this->color = White;
	}

	Line(Vertex v1, int x2, int y2, int thickness, Color c) {
		this->startPt = v1;
		this->endPt = Vertex{ x2, y2 };
		this->thickness = thickness;
		this->color = c;
	}
	Line(int x1, int y1, Vertex v2, int thickness, Color c) {
		this->startPt = Vertex{ x1, y1 };
		this->endPt = v2;
		this->thickness = thickness;
		this->color = c;
	}

	Line(Vertex v1, int x2, int y2, int thickness);
	Line(int x1, int y1, Vertex v2, int thickness);
	
	Line(Vertex v1, int x2, int y2, Color c);
	Line(int x1, int y1, Vertex v2, Color c);

	Line(Vertex v1, int x2, int y2);
	Line(int x1, int y1, Vertex v2);*/
};

//class Line {
	Vertex startPt;
	Vertex endPt;
	int thickness;
	Color color;

	Line() {
		Vertex startPt = Vertex();
		Vertex endPt = Vertex();
		int thickness = 3;
		Color color = White;
	}

	void Draw() {

	}
};