#pragma once
#include "Route.h"
using namespace std;

void ReadRouteFromConsole(Route& route) {
	int number;
	int avgDurationMinutes;
	int frequency;
	int stopCounter;
	cout << "Введите номер маршрута: ";
	try {
		cin >> number;
		if (number > 0) {}
		else {
			throw (number);
		}
	}
	catch (int number) {
		cout << "Введите корректный номер маршрута: "; cin >> number;
	}
	route.numberRoute = number;
	cout << endl << "Введите среднюю продолжительность маршрута: ";
	try {
		cin >> avgDurationMinutes;
		if (avgDurationMinutes > 0) {}
		else {
			throw(avgDurationMinutes);
		}
	}
	catch (int avgDurationminutes) {
		cout << "Введите корректную продолжительность: "; cin >> avgDurationminutes;
	}
	route.avgDurationMinutes = avgDurationMinutes;
	cout << "Введите частоту смены автобусов: ";
	try {
		cin >> frequency;
		if (frequency > 0) {}
		else {
			throw(frequency);
		}
	}
	catch (int frequency) {
		cout << "Введите корректную частоту: "; cin >> frequency;
	}
	route.avgfrequencyMinutes = frequency;
	cout << "Введите количество остановок: ";
	try {
		cin >> stopCounter;
		if (stopCounter > 0) {}
		else {
			throw(stopCounter);
		}
	}
	catch (int stopCounter) {
		cout << "Введите корректное количество: "; cin >> stopCounter;
	}
	route.stopNumber = stopCounter;
	for (int i = 0; i < stopCounter; i++) {
		cout << "Введите название остановки №" << i << ": "; cin >> route.titles[i];
	}
};

void WriteRouteToConsole(Route& route) {
	cout << "Маршрут №" << route.numberRoute << endl;
	cout << "Имеет " << route.stopNumber << " остановок:" << endl;
	for (int i = 0; i < route.stopNumber; i++) {
		cout << "Остановка №" << i << " " << route.titles[i];
	}
	cout << endl << "Автобусы ходят каждые " << route.avgfrequencyMinutes << " минут" << endl;
	cout << "В среднем между остановками проходит " << route.avgDurationMinutes << " минут";
};

int FindRouteTo(Route* route, string title, int routeCount) {
	for (int i = 0; i < routeCount; i++) {
		for (int j = 0; j < route[i].stopNumber; j++) {
			if (route[i].titles[j] == title) {
				return i;
			}
		}
	}
	return -1;
};

void DemoRoute() {
	const int n = 3;
	int index;
	string title;
	Route* routes = new Route[n];
	for (int i = 0; i < n; i++) {
		ReadRouteFromConsole(routes[i]);
	}
	for (int i = 0; i < n; i++) {
		WriteRouteToConsole(routes[i]);
		cout << endl;
	}
	cout << "Введите название остановки для поиска: "; cin >> title;
	index = FindRouteTo(routes, title, n);
	if (index == -1) {
		cout << "Данного маршрута нет в списке";
	}
	else {
		WriteRouteToConsole(routes[index]);
	}
	delete routes;
};