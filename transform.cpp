#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

void add_tr(int& x, int & y, int m, int n) {
	x += m;	
	y += n;
}

void add_tr2(int& x, int& y, int& z, int m, int n, int k) {
	x += m;
	y += n;
	z += k;
}

Shape transform::shift(int m, int n, int k)
{
	switch (shape.getType())
	{
	case Shape::line:
		add_tr(shape.x1, shape.y1, m, n);
		add_tr(shape.x2, shape.y2, m, n);
		break;
	case Shape::sqr:
		add_tr(shape.x1, shape.y1, m, n);
		add_tr(shape.x2, shape.y2, m, n);
		add_tr(shape.x3, shape.y3, m, n);
		add_tr(shape.x4, shape.y4, m, n);
		break;
	case Shape::cube:
		add_tr2(shape.x1, shape.y1, shape.z1, m, n, k);
		add_tr2(shape.x2, shape.y2, shape.z2, m, n, k);
		add_tr2(shape.x3, shape.y3, shape.z3, m, n, k);
		add_tr2(shape.x4, shape.y4, shape.z4, m, n, k);
		add_tr2(shape.x5, shape.y5, shape.z5, m, n, k);
		add_tr2(shape.x6, shape.y6, shape.z6, m, n, k);
		add_tr2(shape.x7, shape.y7, shape.z7, m, n, k);
		add_tr2(shape.x8, shape.y8, shape.z8, m, n, k);
		break;
	}
	return shape;
}

void multi_tr(int& angle,int variable) {
	angle *= variable;
	
}

Shape transform::scaleX(int a)
{
	switch (shape.getType())
	{
	case Shape::line:
		multi_tr(shape.x1, a);
		multi_tr(shape.x2, a);
		break;
	case Shape::sqr:
		multi_tr(shape.x1, a);
		multi_tr(shape.x2, a);
		multi_tr(shape.x3, a);
		multi_tr(shape.x4, a);
		break;
	case Shape::cube:
		multi_tr(shape.x1, a);
		multi_tr(shape.x2, a);
		multi_tr(shape.x3, a);
		multi_tr(shape.x4, a);
		multi_tr(shape.x5, a);
		multi_tr(shape.x6, a);
		multi_tr(shape.x7, a);
		multi_tr(shape.x8, a);
		break;
	}
	return shape;
}

Shape transform::scaleY(int d)
{
	switch (shape.getType())
	{
	case Shape::line:
		multi_tr(shape.y1, d);
		multi_tr(shape.y2, d);
		break;
	case Shape::sqr:
		multi_tr(shape.y1, d);
		multi_tr(shape.y2, d);
		multi_tr(shape.y3, d);
		multi_tr(shape.y4, d);
		break;
	case Shape::cube:
		multi_tr(shape.y1, d);
		multi_tr(shape.y2, d);
		multi_tr(shape.y3, d);
		multi_tr(shape.y4, d);
		multi_tr(shape.y5, d);
		multi_tr(shape.y6, d);
		multi_tr(shape.y7, d);
		multi_tr(shape.y8, d);
		break;
	}
	return shape;
}

Shape transform::scaleZ(int e)
{
	switch (shape.getType())
	{
	case Shape::line:
		multi_tr(shape.z1, e);
		multi_tr(shape.z2, e);
		break;
	case Shape::sqr:
		multi_tr(shape.z1, e);
		multi_tr(shape.z2, e);
		multi_tr(shape.z3, e);
		multi_tr(shape.z4, e);
		break;
	case Shape::cube:
		multi_tr(shape.z1, e);
		multi_tr(shape.z2, e);
		multi_tr(shape.z3, e);
		multi_tr(shape.z4, e);
		multi_tr(shape.z5, e);
		multi_tr(shape.z6, e);
		multi_tr(shape.z7, e);
		multi_tr(shape.z8, e);
		break;
	}
	return shape;
}

void div_tr(int& x,int & y, int variable) {
	x /= variable;
	y /= variable;

}

void div_tr2(int& x, int& y, int& z, int variable) {
	x /= variable;
	y /= variable;

}

Shape transform::scale(int s)
{
	switch (shape.getType())
	{
	case Shape::line:
		div_tr(shape.x1, shape.y1, s);
		div_tr(shape.x2, shape.y2, s);
		break;
	case Shape::sqr:
		div_tr(shape.x1, shape.y1, s);
		div_tr(shape.x2, shape.y2, s);
		div_tr(shape.x3, shape.y3, s);
		div_tr(shape.x4, shape.y4, s);
		break;
	case Shape::cube:
		div_tr2(shape.x1, shape.y1, shape.z1, s);
		div_tr2(shape.x2, shape.y2, shape.z2, s);
		div_tr2(shape.x3, shape.y3, shape.z3, s);
		div_tr2(shape.x4, shape.y4, shape.z4, s);
		div_tr2(shape.x5, shape.y5, shape.z5, s);
		div_tr2(shape.x6, shape.y6, shape.z6, s);
		div_tr2(shape.x7, shape.y7, shape.z7, s);
		div_tr2(shape.x8, shape.y8, shape.z8, s);
		break;
	}

	return shape;
}