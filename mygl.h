#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

class Point{
public:
	int x;
	int y;
	
	Point(){
	}
	
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Color{
public:
	int red;
	int green;
	int blue;
	int alpha;
	
	Color(){}
	
	Color(int r, int g, int b, int a){
		red = r;
		green = g;
		blue = b;
		alpha = a;
	}
};

class Pixel{
public:
	Point p;
	Color c;
	
	Pixel(Point p, Color c){
		this->p = p;
		this->c = c;
	}
};

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

Color RED = Color(255,0,0,255);
Color GREEN = Color(0,255,0,255);
Color BLUE = Color(0,0,255,255);
	
void PutPixel(Point, Color);
void DrawLine(Point, Point, Color);
void DrawTriangle(Point, Point, Point, Color);
