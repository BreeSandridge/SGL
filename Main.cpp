#include "Main.h"
#include "Shape.h"
#include "Pipeline.h"
#include <iostream>

Pipeline view(int argc, char* argv[]) {

	Pipeline p = Pipeline();
	/*
	Shape s = Shape();

	POINT p1 = { 20,20 };
	s.vertices.push_back(p1);

	POINT p2 = { 200,30 };
	s.vertices.push_back(p2);

	POINT p3 = { 500,500 };
	s.vertices.push_back(p3);
	*/
	const auto c = Circle({500,500}, {200,200});
	p.shapes.push_back(c);

/*
	POINT BL = { p.config.currentResolutionWidth*.7,p.config.currentResolutionHeight*.5 };
	POINT TR = { p.config.currentResolutionWidth * .8,p.config.currentResolutionHeight * .3 };
	RectangleShape r = RectangleShape(BL, TR);

	
	p.shapes.push_back(r);
*/

	return p;
}
