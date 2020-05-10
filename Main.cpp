#include "GraphicsLib.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;

#define SPEED 1

/*
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
	circle* c;
	identifier* i;
	Node(int _x, int _y, int _radius, string _msg, Color _c) {
		c = new circle(_x, _y, _radius, _c, false);
		i = new identifier(_x, _y, _radius / 2, White, _msg);
	}
};

void drawIdentifier(identifier i) {
	DrawGDIString(i.x, i.y, i.font_size, i.c, i.s);
}
void drawNode(Node n) {
	drawCircle(*n.c);
	drawIdentifier(*n.i);
}*/

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

void drawCircle(circle c) {
	DrawCircle(c.x, c.y, c.radius, c.c, c.filled);
}

struct node {
	circle* c;
	float x_vel, y_vel, x_force, y_force;

	explicit node(circle* _c) : c(_c), x_vel(0.0f), y_vel(0.0f){}
	explicit node (int _x, int _y, int r) : c(new circle(_x,_y,r,White,false)), x_vel(0.0f), y_vel(0.0f){}
};

void drawNode(node n) {
	drawCircle(*n.c);
}

struct edge {
	node n1, n2;
	const float length = 1.0f;
	int thickness;
	Color c;
	edge(node _n1, node _n2) : n1(_n1), n2(_n2), thickness(4), c(White){}
};

void drawEdge(edge l) {
	DrawLine(l.n1.c->x, l.n1.c->y, l.n2.c->x, l.n2.c->y, l.thickness, l.c);
}

// Fs = kx					;	Spring Eqn				:	k = spring const,	x = displacement
// Fe = ke ((q1*q2)/r^2)	;	Charged Particle Eqn	:	ke = Coulombs const (8.987 * 10^9), q1 and q1 are signed charges, r is the distance between particles
// vf = vi + (F/m)t			;	Force to vel

void apply_spring_force(const vector<edge>& edges) {
	for (auto e: edges) {
		// spring coeff
		const auto k = 0.5f;

		// x and y dist between to particles
		const float length = e.n1.c->x - e.n2.c->x;
		const float height = e.n1.c->y - e.n2.c->y;
		
		// uses distance pythagorean thm to calculate hyp
		// a^2 + b^2 = c^2
		const auto hyp = sqrtf(length * length + height * height);

		// how far the spring is stretched from original location
		const auto displacement = hyp - e.length;

		// gets direction of force
		const auto dir_x = e.n1.c->x > e.n2.c->x;
		const auto dir_y = e.n1.c->y > e.n2.c->y;

		// angles of the triangle
		const auto theta = abs(asinf(height / hyp));

		// calculates the angle of force for each particle
		float force_theta_a;
		float force_theta_b;
		if (dir_x) {
			if(dir_y) {
				force_theta_a = theta;
				force_theta_b = 180 + theta;
			} else {
				force_theta_a = 360 - theta;
				force_theta_b = 180 - theta;
			}
		} else {
			if (dir_y) {
				force_theta_a = 180 - theta;
				force_theta_b = 360 - theta;
			}
			else {
				force_theta_a = 180 + theta;
				force_theta_b = theta;
			}
		}

		// uses the angle, k const and spring displacement to determine the x force vector
		const auto partial_x_force_a = k * displacement * cosf(force_theta_a);
		const auto partial_x_force_b = k * displacement * cosf(force_theta_b);

		// uses the angle, k const and spring displacement to determine the y force vector
		const auto partial_y_force_a = k * displacement * sinf(force_theta_a);
		const auto partial_y_force_b = k * displacement * sinf(force_theta_b);

		// adds that force to the nodes themselves
		e.n1.x_force += partial_x_force_a;
		e.n2.x_force += partial_x_force_b;
		e.n1.y_force += partial_y_force_a;
		e.n2.x_force += partial_y_force_b;
	}
}

void apply_particle_force(const vector<node>& nodes) {
	const float k = 9 * 10 ^ 9;
	const float charge = 1;


	float force_theta_a;
	float force_theta_b;

	node* node_a = nullptr;
	node* node_b = nullptr;
	
	for (auto i = 0; i < nodes.size()-1; i++) {
		for (auto j = 1; j < nodes.size(); j++) {
			*node_a = nodes.at(i);
			*node_b = nodes.at(j);

			const float height = node_a->c->y - node_b->c->y;
			const float width = node_a->c->x - node_b->c->x;

			const auto dist = sqrtf((height * height) + (width * width));

			const auto dir_x = node_a > node_b;
			const auto dir_y = node_a > node_b;


			const auto theta = abs(asinf(height / dist));

			if (dir_x) {
				if (dir_y) {
					force_theta_a = theta;
					force_theta_b = 180 + theta;
				} else {
					force_theta_a = 360 - theta;
					force_theta_b = 180 - theta;
				}
			} else {
				if (dir_y) {
					force_theta_a = 180 - theta;
					force_theta_b = 360 - theta;
				} else {
					force_theta_a = 180 + theta;
					force_theta_b = theta;
				}
			}

			const auto undirected_force = k * ((charge * charge) / (dist * dist));

			const auto partial_x_force_a = undirected_force * cosf(force_theta_a);
			const auto partial_y_force_a = undirected_force * sinf(force_theta_a);

			const auto partial_x_force_b = undirected_force * cosf(force_theta_b);
			const auto partial_y_force_b = undirected_force * sinf(force_theta_a);

			node_a->x_force += partial_x_force_a;
			node_a->y_force += partial_y_force_a;

			node_b->x_force += partial_x_force_b;
			node_b->y_force += partial_y_force_b;
		}
	}
}

void main() {  // NOLINT(bugprone-exception-escape)
	// INITIALIZATION 
	UseAntiAliasing(true);

	clock_t c();
	double duration

	vector<node> nodes;
	node n0 = node(700, 700, 20);
	nodes.push_back(n0);
	node n1 = node(700, 700, 20);
	nodes.push_back(n1);
	node n2 = node(700, 700, 20);
	nodes.push_back(n2);
	node n3 = node(700, 700, 20);
	nodes.push_back(n3);
	node n4 = node(700, 700, 20);
	nodes.push_back(n4);

	vector<edge> edges;
	edge e0 = edge(n0, n1);
	edges.push_back(e0);
	edge e1 = edge(n1, n2);
	edges.push_back(e1);
	edge e2 = edge(n2, n3);
	edges.push_back(e2);
	edge e3 = edge(n3, n4);
	edges.push_back(e3);
	edge e4 = edge(n4, n1);
	edges.push_back(e4);

	for (edge e : edges) {
		drawEdge(e);
	}
	for (node n : nodes) {
		drawNode(n);
	}

	c.
	
}
