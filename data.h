//klasa reprezentujaca date

#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
using namespace std;


class Data
{
private:
	friend class Zdarzenie;		//klasa Zdarzenie ma dostep do prywatnych danych klasy Data
	friend class Terminarz;
	int rok;
	int miesiac;
	int dzien;
	int dzien_tygodnia;
	int godzina;
	int minuta;
public:
	Data();
	~Data();
	bool ustaw_date(int r, int m, int d);
	bool ustaw_godzine(int h, int m);
	bool operator==(Data & data);
	friend ostream & operator<<(ostream & os, const Data & data);
};

#endif