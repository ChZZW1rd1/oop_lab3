#include <iostream>
#include "structs/Book.h"
#include "structs/Route.h"
#include "classes/Point.h"
#include "classes/Rectangle.h"
#include "classes/Time.h"
#include "classes/Flight.h"
#include "classes/SongAlbum.h"
using namespace std;

void DemoRectangleWithPoint() {
	double Xcentre = 0; double Ycentre = 0;
	Rectangle* rectangles = new Rectangle[5];
	rectangles[0] = Rectangle(1.0, 2.0, -5.0, 6.0);
	rectangles[1] = Rectangle(2.4, 15.18, 5.55, -6.66);
	rectangles[2] = Rectangle(11.8, 9.6, 0.0, 0.0);
	rectangles[3] = Rectangle(3.55, 4.4, 0.0, 0.0);
	rectangles[4] = Rectangle(8.1, 6.7, 16.0, 25.5);
	for (int i = 0; i < 5; i++) {
		rectangles[i].WriteRectangleToConsole();
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		Xcentre += rectangles[i].GetCentre()->GetCoordX();
		Ycentre += rectangles[i].GetCentre()->GetCoordY();
	}
	cout << "Xcenter=" << Xcentre / 5 << "; YCenter=" << Ycentre / 5 << ";";
	delete[] rectangles;
}

void DemoFlightWithTIme() {
	Flight* flights = new Flight[5];
	flights[0] = Flight("Москва", "Томск", "A49", 2022, 7, 11, 10, 35, 2022, 7, 11, 15, 55);
	flights[1] = Flight("Томск", "Москва", "S404", 2022, 7, 23, 23, 55, 2022, 7, 24, 5, 40);
	flights[2] = Flight("Новосибирск", "Токио", "Y518", 2021, 10, 15, 11, 25, 2021, 10, 15, 21, 30);
	flights[3] = Flight("Омск", "Пермь", "A37", 2022, 3, 18, 2, 30, 2022, 3, 18, 3, 30);
	flights[4] = Flight("Челябинск", "Новороссийск", "GT55", 2022, 6, 9, 8, 00, 2022, 6, 9, 23, 30);
	for (int i = 0; i < 5; i++) {
		flights[i].WriteFlightToConsole();
	}
	cout << "Время в полете: " << endl;
	for (int i = 0; i < 5; i++){
		flights[i].CalculateTime();
	}
}

void DemoBand() {
	Song song_1 = Song(Phonk, 3, "lost");
	Song song_2 = Song(Rap, 3, "OKAY");
	Song song_3 = Song(Rap, 2, "hollow");
	Song song_4 = Song(Phonk, 2, "make up");
	Song song_5 = Song(Rap, 3, "HELP!");
	Song songs_1[5] = { song_1, song_2, song_3, song_4, song_5 };
	Album album_1 = Album("i don't care", 2019, 5, songs_1);
	Song song_6 = Song(HipHop, 3, "I Can't Sleep");
	Song song_7 = Song(Rap, 2, "Empty Room");
	Song song_8 = Song(Rock, 1, "Afraid");
	Song song_9 = Song(HipHop, 2, "Don't Go Outside");
	Song song_10 = Song(Rock, 3, "Don't Look At Me");
	Song songs_2[5] = { song_6, song_7, song_8, song_9, song_10 };
	Album album_2 = Album("The Breakfast Club", 2020, 5, songs_2);
	Song song_11 = Song(HipHop, 1, "Run");
	Song song_12 = Song(Rap, 2, "Party At The Cemetery");
	Song song_13 = Song(Rap, 1, "Bad Vibes");
	Song song_14 = Song(Rock, 2, "Matchstick");
	Song song_15 = Song(Rock, 3, "Jump");
	Song songs_3[5] = { song_11, song_12, song_13, song_14, song_15 };
	Album album_3 = Album("Party At The Cemetery", 2021, 5, songs_3);
	Album albums[3] = { album_1, album_2, album_3 };
	Band POORSTACY = Band("POORSTACY", "One member", 3, albums);
	Song *song; string songNameToFind = "Don't Look At Me";
	song = POORSTACY.FindSong(songNameToFind);
	if (song == nullptr) {
		cout << "Song wasn't found " << endl;

	}
	else {
		cout << "Song was found " << endl;
		song->OutSelf();
	}
	Song* songToFind = &song_9;
	Album* AlbumToFind = POORSTACY.FindAlbum(songToFind);
	if (AlbumToFind == nullptr) {
		cout << "No album with that song" << endl;
	}
	else{
		cout << endl << "The song <<" << songToFind->GetName() << ">> has found in album: " << endl;
		AlbumToFind->OutSelf();
		cout << endl;
	}
	int allSongsCount = 0;
	cout << "All songs of " << POORSTACY.GetName() << ":" << endl;
	Song *allSongs = POORSTACY.GetAllSongs(allSongsCount);
	for (int i = 0; i < allSongsCount; i++) {
		allSongs[i].OutSelf();
		cout << endl;
	}
	allSongsCount = 0;
	Song *allSongsGenre = POORSTACY.GetAllGenreSongs(allSongsCount, Rock);
	cout << "All rock songs of " << POORSTACY.GetName() << ":" << endl;
	for (int i = 0; i < allSongsCount; i++) {
		allSongsGenre[i].OutSelf();
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int item;
	cout << "DemoBook - 1" << endl;
	cout << "DemoRoute - 2" << endl;
	cout << "DemoRectangle - 3" << endl;
	cout << "DemoflightWithTime - 4" << endl;
	cout << "DemoBand - 5" << endl;
	cout << "Введите номер задания: ";
	cin >> item; cout << endl;
	switch (item) {
	case 1: {
		DemoBook();
		break;
	}
	case 2: {
		DemoRoute();
		break;
	}
	case 3: {
		DemoRectangleWithPoint();
		break;
	}
	case 4: {
		DemoFlightWithTIme();
		break;
	}
	case 5: {
		DemoBand();
		break;
	}
	}
}


