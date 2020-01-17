#pragma once
//https://www.programiz.com/cpp-programming/inheritance
	//create shape stuff.

#include "Config.h"
#include "Shape.h"
#include <vector>

class Pipeline {
public:
	std::vector<Shape> shapes;
	Config config;
	Pipeline();

};

