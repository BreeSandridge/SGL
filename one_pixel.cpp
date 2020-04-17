#include "GraphicsLib.h"

//
// Example 1 - Hello World
//
// Draws 3 different pixels to the middle of the screen using the 3 methods.
//


void main()
{
	SetPixel(80, 60, Yellow);


	Point p;
	p.x = 81;
	p.y = 60;
	p.color = Blue;
	DrawPoint(p);


	DrawPoint(82, 60, Magenta);
}
