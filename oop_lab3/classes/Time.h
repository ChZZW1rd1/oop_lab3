#pragma once
#include <iostream>

using namespace std;

class Time {
private:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
public:
	void SetYear(int year) {
		if (year > 2022 || year < 0) {
			throw exception("¬ведите корректный номер года");
		}
		this->Year = year;
	};
	void SetMonth(int month) {
		if (month > 12 || month < 0) {
			throw exception("¬ведите корректный номер мес€ца");
		}
		this->Month = month;
	}
	void SetDay(int day) {
		if (day > 30 || day < 0) {
			throw exception("¬ведите корректный номер дн€");
		}
		this->Day = day;
	}
	void SetHour(int hour) {
		if (hour > 24 || hour < 0) {
			throw exception("¬ведите коррекетный час");
		}
		this->Hour = hour;
	}
	void SetMinute(int minute) {
		if (minute > 60 || minute < 0) {
			throw exception("¬ведите корректные минуты");
		}
		this->Minute = minute;
	}
	int GetYear() {
		return this->Year;
	}
	int GetMonth() {
		return this->Month;
	}
	int GetDay() {
		return this->Day;
	}
	int GetHour() {
		return this->Hour;
	}
	int GetMinute() {
		return this->Minute;
	}
	Time() {
		SetYear(1910);
		SetMonth(1);
		SetDay(1);
		SetHour(0);
		SetMinute(0);
	}
	Time(int year, int month, int day, int hour, int minute) {
		SetYear(year);
		SetMonth(month);
		SetDay(day);
		SetHour(hour);
		SetMinute(minute);
	}
};