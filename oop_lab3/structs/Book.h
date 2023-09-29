#pragma once
#include <iostream>

using namespace std;

struct Book {
	int year;
	string name;
	int pages;
	string authors[10];
	int countAuthors;
};

void DemoBook();
void ReadBookFromConsole(Book& book);
void WriteBookToConsole(Book& book);
int FindBookByAuthor(Book* books, int booksCount, string author);
