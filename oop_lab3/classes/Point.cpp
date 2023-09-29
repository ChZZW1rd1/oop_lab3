#pragma once
#include "Point.h"
#include <iostream>

using namespace std;

void Point::SetCoordX(double coordX) {
	this->_coordX = coordX;
}

void Point::SetCoordY(double coordY) {
	this->_coordY = coordY;
}

double Point::GetCoordX() {
	return this->_coordX;
}

double Point::GetCoordY() {
	return this->_coordY;
}

Point::Point(double coordX, double coordY) {
	SetCoordX(coordX);
	SetCoordY(coordY);
}

Point::Point() {
	SetCoordX(0);
	SetCoordY(0);
}
