#pragma once
#include"Time.h"
#include <iostream>

using namespace std;

class Flight {
private:
	Time departureTime;
	Time arrivalTime;
	string arrivalPoint;
	string departurePoint;
	string nameFlight; // Номер может содержать буквы => string
public:
	void SetDepartureTime(int year, int month, int day, int hour, int minute) {

		this->departureTime = Time(year, month, day, hour, minute);
	}
	void SetArrivalTime(int year, int month, int day, int hour, int minute) {
		if (year < departureTime.GetYear() || month < departureTime.GetMonth() || day < departureTime.GetDay()
			|| (day == departureTime.GetDay()) && ((hour < departureTime.GetHour()) || (hour == departureTime.GetHour() && minute < departureTime.GetMinute()))) {
			throw exception("Введено некорректное время прилета");
		}
		this->arrivalTime = Time(year, month, day, hour, minute);
	}
	void SetArrivalPoint(string name) {
		this->arrivalPoint = name;
	}
	void SetDeparturePoint(string name) {
		this->departurePoint = name;
	}
	void SetName(string name) {
		this->nameFlight = name;
	}

	Time GetDepartureTime() {
		return this->departureTime;
	}
	Time GetArrivalTime() {
		return this->arrivalTime;
	}
	string GetArrivalPoint() {
		return this->arrivalPoint;
	}
	string GetDeparturePoint() {
		return this->departurePoint;
	}
	string GetNameFlight() {
		return this->nameFlight;
	}

	Flight() {
		SetArrivalPoint("none");
		SetDeparturePoint("none");
		SetArrivalTime(1911, 1, 1, 0, 0);
		SetDepartureTime(1910, 1, 1, 0, 0);
		SetName("none");
	}
	Flight(string arrivalName, string departureName, string name, int dyear, int dmonth, int dday, int dhour, int dminute,
	int ayear, int amonth, int aday, int ahour, int aminute) {
		SetDeparturePoint(departureName);
		SetArrivalPoint(arrivalName);
		SetDepartureTime(dyear, dmonth, dday, dhour, dminute);
		SetArrivalTime(ayear, amonth, aday, ahour, aminute);
		SetName(name);
	}
	void WriteFlightToConsole() {
		cout << this->GetNameFlight() << " " << this->GetDeparturePoint() << "-" << this->GetArrivalPoint() << " Вылет "
			<< this->GetDepartureTime().GetMonth() << "." << this->GetDepartureTime().GetYear() << " "
			<< this->GetDepartureTime().GetHour() << ":" << this->GetDepartureTime().GetMinute()
			<< " Прибытие " << this->GetArrivalTime().GetMonth() << "." << this->GetArrivalTime().GetYear() << " "
			<< this->GetArrivalTime().GetHour() << ":" << this->GetArrivalTime().GetMinute() << endl;
	}
	void CalculateTime() {
		int minutes = 0; int hours = 0;
		if (this->GetArrivalTime().GetMinute() < this->GetDepartureTime().GetMinute()) {
			minutes = ((60 - this->GetDepartureTime().GetMinute()) + this->GetArrivalTime().GetMinute());
		}
		else {
			minutes = this->GetArrivalTime().GetMinute() - this->GetDepartureTime().GetMinute();
		}
		if (this->GetArrivalTime().GetHour() < this->GetDepartureTime().GetHour()) {
			hours += ((24 - this->GetDepartureTime().GetHour()) + this->GetArrivalTime().GetHour() - 1);
		}
		else {
			hours +=  (this->GetArrivalTime().GetHour() - this->GetDepartureTime().GetHour());
		}
		cout << this->GetNameFlight() << " " << this->GetDeparturePoint() << "-" << this->GetArrivalPoint() << " Время полета: " <<
			hours << "ч " << minutes << " мин" << endl;
	}
};