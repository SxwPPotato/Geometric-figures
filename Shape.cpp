#define _USE_MATH_DEFINES
#include"Shape.h"
#include<cmath>


void add_tr(int& x, int& y, int m, int n) {
	x += m;
	y += n;
}

void add_tr2(int& x, int& y, int& z, int m, int n, int k) {
	x += m;
	y += n;
	z += k;
}

Shape Shape::shift(Shape& sh, int m, int n, int k) {

	switch (sh.getType())
	{
	case Shape::line:
		add_tr(sh.x1, sh.y1, m, n);
		add_tr(sh.x2, sh.y2, m, n);
		break;
	case Shape::sqr:
		add_tr(sh.x1, sh.y1, m, n);
		add_tr(sh.x2, sh.y2, m, n);
		add_tr(sh.x3, sh.y3, m, n);
		add_tr(sh.x4, sh.y4, m, n);
		break;
	case Shape::cube:
		add_tr2(sh.x1, sh.y1, sh.z1, m, n, k);
		add_tr2(sh.x2, sh.y2, sh.z2, m, n, k);
		add_tr2(sh.x3, sh.y3, sh.z3, m, n, k);
		add_tr2(sh.x4, sh.y4, sh.z4, m, n, k);
		add_tr2(sh.x5, sh.y5, sh.z5, m, n, k);
		add_tr2(sh.x6, sh.y6, sh.z6, m, n, k);
		add_tr2(sh.x7, sh.y7, sh.z7, m, n, k);
		add_tr2(sh.x8, sh.y8, sh.z8, m, n, k);
		break;
	}
	return sh;
}

void multi_tr(int& angle, int variable) {
	angle *= variable;

}

Shape Shape::scaleX(Shape& shape, int a)
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

Shape Shape::scaleY(Shape & shape,int d)
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

Shape Shape::scaleZ(Shape& shape,int e)
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

void div_tr(int& x, int& y, int variable) {
	x /= variable;
	y /= variable;

}

void div_tr2(int& x, int& y, int& z, int variable) {
	x /= variable;
	y /= variable;

}

Shape Shape::scale(Shape & shape,int s)
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


Line::Line(int _type, angle1 ang1, angle2 ang2)
{
	
	type = _type;
	x1 = ang1._x1; y1 = ang1._y1;
	x2 = ang2._x2; y2 = ang2._y2;
	volume = 0;
	square = 0;
}



Rectangle::Rectangle(int _type, angle1 ang1, angle2 ang2, angle3 ang3, angle4 ang4)
{
	type = _type;
	x1 = ang1._x1; y1 = ang1._y1;
	x2 = ang2._x2; y2 = ang2._y2;
	x3 = ang3._x3; y3 = ang3._y3;
	x4 = ang4._x4; y4 = ang4._y4;

	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);

	volume = 0;
	square = a * b;
}

Cube::Cube(int _type, angle1 ang1, angle2 ang2, angle3 ang3, angle4 ang4, angle5 ang5, angle6 ang6, angle7 ang7, angle8 ang8) 
{
	type = _type;
	x1 = ang1._x1; y1 = ang1._y1; z1 = ang1._z1;
	x2 = ang2._x2; y2 = ang2._y2; z2 = ang2._z2;
	x3 = ang3._x3; y3 = ang3._y3; z3 = ang3._z3;
	x4 = ang4._x4; y4 = ang4._y4; z4 = ang4._z4;
	x5 = ang5._x5; y5 = ang5._y5; z5 = ang5._z5;
	x6 = ang6._x6; y6 = ang6._y6; z6 = ang6._z6;
	x7 = ang7._x7; y7 = ang7._y7; z7 = ang7._z7;
	x8 = ang8._x8; y8 = ang8._y8; z8 = ang8._z8;

	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);

	volume = a * b * c;
	square = 2 * a * b + 2 * a * c + 2 * b * c;

}

Circle::Circle(int _type, angle1 ang1, double R, double H) 
{
	type = _type;
	x1 = ang1._x1; y1 = ang1._y1;
	radius = R;

	volume = 0;
	square = M_PI * R * R;
}

Cylinder::Cylinder(int _type, angle1 ang1, double R, double H)
{
	type = _type;
	x1 = ang1._x1; y1 = ang1._y1;
	radius = R;
	height = H;

	volume = M_PI * R * R * height;
	square = M_PI * R * R + 2 * R * height;
}
