#include "GraphicsLib.h"
#include <string>
//
// Example 1 - Hello World
//
// Draws a single pixel to the middle of the screen.
//

using namespace std;

struct circle {
	int x, y, radius;
	Color c;
	bool filled;
	circle(int _x, int _y, int _radius, Color _c, bool _filled) {
		x = _x;
		y = _y;
		radius = _radius;
		c = _c;
		filled = _filled;
	}
};


struct identifier
{
	string s;
	int x, y, font_size;
	Color c;
	identifier(int _x, int _y, int _font_size, Color _c, string _s) {
		s = _s;
		x = _x;
		y = _y;
		c = _c;
		font_size = _font_size;
	}
};
struct Node {
	circle c;
	identifier i;
	Node(int _x, int _y, int _radius, string _msg, Color _c) {
		c = circle(_x, _y, _radius, _c, false);
		i = identifier(_x, _y, _radius / 10, White, _msg);
	}
};
void drawCircle(circle c) {
	DrawCircle(c.x, c.y, c.radius, c.c, c.filled);
}
void drawIdentifier(identifier i) {
	DrawGDIString(i.x, i.y, i.font_size, i.c, i.s);
}
void drawNode(Node n) {
	drawCircle(n.c);
	drawIdentifier(n.i);
}

void main() {
	UseAntiAliasing(true);
	circle c = circle(800, 600, 100, Blue, false);
	drawCircle(c);


	identifier i = identifier(400, 400, 20, White, "hello");
	drawIdentifier(i);

	Node n


	DrawGDIString(100, 100, 20, Blue, "hello");
	SetPixel(80, 60, Yellow);
}
