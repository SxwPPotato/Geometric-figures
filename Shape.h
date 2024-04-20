#pragma once
#include<string>

struct angle1 {
	int _x1;
	int _y1;
	int _z1;
};

struct angle2 {
	int _x2;
	int _y2;
	int _z2;
};

struct angle3 {
	int _x3;
	int _y3;
	int _z3;
};

struct angle4 {
	int _x4;
	int _y4;
	int _z4;
};

struct angle5 {
	int _x5;
	int _y5;
	int _z5;
};

struct angle6 {
	int _x6;
	int _y6;
	int _z6;
};

struct angle7 {
	int _x7;
	int _y7;
	int _z7;
};

struct angle8 {
	int _x8;
	int _y8;
	int _z8;
};

class Shape
{
public:

	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;

	Shape() = default;
	
	int getType() { return type; }



	Shape shift(Shape& sh,int m, int n, int k);
	Shape scaleX(Shape& sh, int a);
	Shape scaleY(Shape& sh, int d);
	Shape scaleZ(Shape& sh, int e);
	Shape scale(Shape& sh, int s);


	int type;
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;
	double volume = 0;
	double square = 0;
	double height = 0;
	double radius = 0;
};




class Line : public Shape {
public:

	Line(int _type, angle1 ang1, angle2 ang2);

};

class Rectangle : public Shape {
public:
	Rectangle(int _type, angle1 ang1, angle2 ang2, angle3 ang3, angle4 ang4);

};

class Cube : public Shape {


public:
	Cube(int type, angle1 ang1, angle2 ang2, angle3 ang3, angle4 ang4, angle5 ang5, angle6 ang6, angle7 ang7, angle8 ang8);

};

class Circle : public Shape {
public:
	Circle(int type, angle1 ang1, double R, double H);

};

class Cylinder : public Shape {

public:
	Cylinder(int type, angle1 ang1, double R, double H);

};