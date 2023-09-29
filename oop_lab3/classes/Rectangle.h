#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

class Rectangle {
private:
	double _lenght;
	double _width;
	Point _centre;
public:
	double GetLenght();
	double GetWight();
	Point* GetCentre();

	void SetLenght(double lenght);
	void SetWidth(double width);
	void SetCentre(double coordX, double CoordY);

	Rectangle(double lenght, double width, double coordX, double CoordY);
	Rectangle();

	void WriteRectangleToConsole();

};