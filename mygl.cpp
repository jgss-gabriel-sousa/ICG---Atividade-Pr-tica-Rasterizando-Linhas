#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;


//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //*************************************************************************

    DrawLine(Point(0,0), Point(255,255), RED);

    DrawTriangle(Point(350,0), Point(250,125), Point(350,100), GREEN);
}

void PutPixel(Point p, Color c) {

    // Calcula o índice do pixel na matriz de pixels:
    int pixelIndex = (p.x + p.y * IMAGE_WIDTH) * 4;

    // Escreve os componentes de cor na posição correta do pixel:
    FBptr[pixelIndex] = c.red;
    FBptr[pixelIndex + 1] = c.green;
    FBptr[pixelIndex + 2] = c.blue;
    FBptr[pixelIndex + 3] = c.alpha;
}

void DrawLine(Point p0, Point p1, Color color)
{
    int x0 = p0.x;
    int y0 = p0.y;
    int x1 = p1.x;
    int y1 = p1.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int error = dx - dy;
    int x = x0;
    int y = y0;

    while (x != x1 || y != y1) {

	PutPixel(Point(x, y), color);

	//Atualiza o Erro
        int newError = 2 * error;
        if (newError > -dy) {
            error -= dy;
            x += sx;
        }
        if (newError < dx) {
            error += dx;
            y += sy;
        }
    }
}

void DrawTriangle(Point p0, Point p1, Point p2, Color color)
{
	DrawLine(p0, p1, color);
	DrawLine(p1, p2, color);
	DrawLine(p2, p0, color);
}
