#pragma once
#include "Book.h"
using namespace std;

void DemoBook() {
	const int n = 3;
	int index;
	string author;
	Book *books = new Book[n];
	for (int i = 0; i < n; i++) {
		ReadBookFromConsole(books[i]);
	}
	for (int i = 0; i < n; i++) {
		WriteBookToConsole(books[i]);
		cout << endl;
	}
	cout << endl << "������� ������ ��� ������: "; cin >> author;
	index = FindBookByAuthor(&books[n], n, author);
	if (index == -1) {
		cout << "������� ������ ��� � ������";
	}
	else {
		WriteBookToConsole(books[index]);
	}
	delete books;
};

void ReadBookFromConsole(Book& book) {
	int count = -1;
	int year = -1;
	cout << "������� �������� �����: ";	cin >> book.name;
	cout << "��� �������: "; cin >> year;
	if (year > 0 and year <= 2022) {
		book.year = year;
	}
	else {
		while (year < 0 or year > 2022) {
			cout << endl << "��� ���� �������������, ���� ������ 2022";
			cout << endl << "������� ���������� ���: ";
			cin >> year;
		}
	}
	cout << "�-�� �������: "; cin >> book.pages;
	cout << "�-�� �������: "; cin >> count;
	if (count < 10 and count > 1) {
		book.countAuthors = count;
	}
	else {
		while (count < 1 or count > 10) {
			cout << endl << "���������� ������� ���� ������ 10 ���� ������ 1 ";
			cout << endl << "������� ���������� ���������� �������: ";
			cin >> count;
		}
		book.countAuthors = count;
	}
	for (int i = 0; i < book.countAuthors; i++) {
		cout << "������� ������ �" << i << ": "; cin >> book.authors[i];
	}
};

void WriteBookToConsole(Book& book) {
	int count = book.countAuthors;
	for (int i = 0; i < count; i++) {
		cout << book.authors[i] << " ";
	}
	cout << book.name << " " << book.year << ". - " << book.pages << "�.";
};

int FindBookByAuthor(Book* books, int booksCount, string author) {
	for (int i = 0; i < booksCount; i++) {
		for (int j = 0; j < books[i].countAuthors; j++) {
			if (books[i].authors[j] == author) {
				return i;
			}
		}
	}
	return -1;
};
