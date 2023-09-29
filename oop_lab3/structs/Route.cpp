#pragma once
#include "Route.h"
using namespace std;

void ReadRouteFromConsole(Route& route) {
	int number;
	int avgDurationMinutes;
	int frequency;
	int stopCounter;
	cout << "������� ����� ��������: ";
	try {
		cin >> number;
		if (number > 0) {}
		else {
			throw (number);
		}
	}
	catch (int number) {
		cout << "������� ���������� ����� ��������: "; cin >> number;
	}
	route.numberRoute = number;
	cout << endl << "������� ������� ����������������� ��������: ";
	try {
		cin >> avgDurationMinutes;
		if (avgDurationMinutes > 0) {}
		else {
			throw(avgDurationMinutes);
		}
	}
	catch (int avgDurationminutes) {
		cout << "������� ���������� �����������������: "; cin >> avgDurationminutes;
	}
	route.avgDurationMinutes = avgDurationMinutes;
	cout << "������� ������� ����� ���������: ";
	try {
		cin >> frequency;
		if (frequency > 0) {}
		else {
			throw(frequency);
		}
	}
	catch (int frequency) {
		cout << "������� ���������� �������: "; cin >> frequency;
	}
	route.avgfrequencyMinutes = frequency;
	cout << "������� ���������� ���������: ";
	try {
		cin >> stopCounter;
		if (stopCounter > 0) {}
		else {
			throw(stopCounter);
		}
	}
	catch (int stopCounter) {
		cout << "������� ���������� ����������: "; cin >> stopCounter;
	}
	route.stopNumber = stopCounter;
	for (int i = 0; i < stopCounter; i++) {
		cout << "������� �������� ��������� �" << i << ": "; cin >> route.titles[i];
	}
};

void WriteRouteToConsole(Route& route) {
	cout << "������� �" << route.numberRoute << endl;
	cout << "����� " << route.stopNumber << " ���������:" << endl;
	for (int i = 0; i < route.stopNumber; i++) {
		cout << "��������� �" << i << " " << route.titles[i];
	}
	cout << endl << "�������� ����� ������ " << route.avgfrequencyMinutes << " �����" << endl;
	cout << "� ������� ����� ����������� �������� " << route.avgDurationMinutes << " �����";
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
	cout << "������� �������� ��������� ��� ������: "; cin >> title;
	index = FindRouteTo(routes, title, n);
	if (index == -1) {
		cout << "������� �������� ��� � ������";
	}
	else {
		WriteRouteToConsole(routes[index]);
	}
	delete routes;
};