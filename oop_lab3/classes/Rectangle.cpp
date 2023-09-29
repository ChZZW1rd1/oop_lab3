#pragma once
#include "Rectangle.h"
#include <iostream>

using namespace std;

Point* Rectangle::GetCentre() {
	return &_centre;
}

double Rectangle::GetLenght() {
	return this->_lenght;
}

double Rectangle::GetWight() {
	return this->_width;
}

void Rectangle::SetLenght(double lenght) {
	if (lenght < 0.0) {
		throw exception("ƒлина не может быть отрицательной");
	}
	this->_lenght = lenght;
}

void Rectangle::SetWidth(double width) {
	if (width < 0.0) {
		throw exception("Ўирина не может быть отрицательной");
	}
	this->_width = width;
}

void Rectangle::SetCentre(double coordX, double coordY) {
	this->_centre.SetCoordX(coordX);
	this->_centre.SetCoordY(coordY);
}

Rectangle::Rectangle(double lenght, double width, double coordX, double CoordY) {
	SetLenght(lenght);
	SetWidth(width);
	SetCentre(coordX, CoordY);
}

Rectangle::Rectangle() {
	SetLenght(0.0);
	SetWidth(0.0);
	SetCentre(0, 0);
}

void Rectangle::WriteRectangleToConsole(){
	cout << "X=" <<this->GetCentre()->GetCoordX() << "; Y=" << this->GetCentre()->GetCoordY() << "; Lenght=";
	cout << this->GetLenght() << "; Width=" << this->GetWight() << ";";
}

