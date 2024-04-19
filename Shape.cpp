#define _USE_MATH_DEFINES
#include"Shape.h"
#include<cmath>

Shape::Shape(int _type, angle1 ang1, angle2 ang2, angle3 ang3, angle4 ang4, angle5 ang5, angle6 ang6, angle7 ang7, angle8 ang8)
{
	type = _type;
	// заполн¤ем координаты фигуры
	switch (type)
	{
	case line:
		x1 = ang1._x1; y1 = ang1._y1;
		x2 = ang2._x2; y2 = ang2._y2;
		break;
	case sqr:
		x1 = ang1._x1; y1 = ang1._y1;
		x2 = ang2._x2; y2 = ang2._y2;
		x3 = ang3._x3; y3 = ang3._y3;
		x4 = ang4._x4; y4 = ang4._y4;
		break;
	case cube:
		x1 = ang1._x1; y1 = ang1._y1; z1 = ang1._z1;
		x2 = ang2._x2; y2 = ang2._y2; z2 = ang2._z2;
		x3 = ang3._x3; y3 = ang3._y3; z3 = ang3._z3;
		x4 = ang4._x4; y4 = ang4._y4; z4 = ang4._z4;
		x5 = ang5._x5; y5 = ang5._y5; z5 = ang5._z5;
		x6 = ang6._x6; y6 = ang6._y6; z6 = ang6._z6;
		x7 = ang7._x7; y7 = ang7._y7; z7 = ang7._z7;
		x8 = ang8._x8; y8 = ang8._y8; z8 = ang8._z8;
		break;
	default:
		break;
	}

	// стороны фигуры
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	// считаем площадь и обьем фигуры
	switch (type)
	{
	case line:
		volume = 0;
		square = 0;		
		break;
	case sqr:
		volume = 0;
		square = a * b;
		break;
	case cube:
		volume = a * b * c;
		square = 2 * a * b + 2 * a * c + 2 * b * c;
		break;
	default:
		break;
	}

	//// считаем объем фигуры
	//switch (type)
	//{
	//case line:
	//	volume = 0;
	//	break;
	//case sqr:
	//	volume = 0;
	//	break;
	//case cube:
	//	volume = a * b * c;
	//	break;
	//default:
	//	break;
	//}

}

Shape::Shape(int type, angle1 ang1, double R, double H)
{
	// заполн¤ем координаты фигуры
	switch (type)
	{
	case circle:
		x1 = ang1._x1; y1 = ang1._y1;
		radius = R;
		break;
	case cylinder:
		x1 = ang1._x1; y1 = ang1._y1;
		radius = R;
		height = H;
		break;
	default:
		break;
	}

	// считаем объем и площадь фигуры
	switch (type)
	{
	case circle:
		volume = 0;
		square = M_PI * R * R;
		break;
	case cylinder:
		volume = M_PI * R * R * height;
		square = M_PI * R * R + 2 * R * height;
		break;
	default:
		break;
	}

	//// считаем объем фигуры
	//switch (type)
	//{
	//case circle:
	//	volume = 0;
	//	break;
	//case cylinder:
	//	volume = M_PI * R * R * height;
	//	break;
	//default:
	//	break;
	//}

}


//int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8