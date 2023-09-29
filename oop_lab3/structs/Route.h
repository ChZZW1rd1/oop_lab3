#pragma once
#include <iostream>

using namespace std;

struct Route {
	int numberRoute;
	int avgDurationMinutes;
	int avgfrequencyMinutes;
	string titles[10];
	int stopNumber;
};

void ReadRouteFromConsole(Route& route);
void WriteRouteToConsole(Route& route);
void DemoRoute();
int FindRouteTo(Route* route, string title, int routeCount);
