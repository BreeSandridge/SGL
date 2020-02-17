#pragma once
//https://www.programiz.com/cpp-programming/inheritance
	//create shape stuff.

#include "Config.h"
#include "Shape.h"
#include <vector>
#include "Line.h"


class Pipeline {
public:
	std::vector<line> lines;
	std::vector<Shape> shapes;
	config config;
	Pipeline();

};

