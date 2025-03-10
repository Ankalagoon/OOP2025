#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height)
{
	int i,j;
	this->canv = new char*[height];
	for (i = 0;i < height;i++) {
		this->canv[i] = new char[width];
		for (j = 0;j < width;j++) {
			this->canv[i][j] = ' ';
		}
	}
	this->width = width;
	this->height = height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray*(ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray*(ray + 1)) {
				this->canv[i][j] = ch;
			}
			else this->canv[i][j] = ' ';
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			if (((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)) {
				this->canv[i][j] = ch;
			}
			else this->canv[i][j] = ' ';
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			if( ( (i==top || i==bottom) && j>=left && j<=right) || (i <= top && i >= bottom && (j == left || j == right))){
				this->canv[i][j] = ch;
			}
			else this->canv[i][j] = ' ';
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			if (i <= top && i >= bottom && j >= left && j <= right) {
				this->canv[i][j] = ch;
			}
			else this->canv[i][j] = ' ';
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->canv[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy,D,y,x;
	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;
	y = y1;

	for (x = x1;x <= x2;x++) {
		SetPoint(x, y, ch);
		if (D > 0) {
			y = y + 1;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void Canvas::Print()
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			printf("%c", this->canv[i][j]);
		}
		printf("\n");
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0;i < height;i++) {
		for (j = 0;j < width;j++) {
			this->canv[i][j] = ' ';
		}
	}
}

