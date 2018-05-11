//klasa reprezentujaca date

#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
using namespace std;


class Data
{
private:						//dane:
	int rok;					
	bool czy_przestepny;				//1-rok przestepny, 0-rok zwykly
	int miesiac;
	int dzien;
	int dzien_tygodnia;
	int godzina;
	int minuta;
	friend class Zdarzenie;				//klasa Zdarzenie ma dostep do prywatnych danych klasy Data
	friend class Terminarz;				//klasa Terminarz ma dostep do prywatnych danych klasy Data
public:
	Data();
	~Data();
	bool ustaw_date(int r, int m, int d);		//ustawiania daty (rok, miesiac, dzien)
	bool ustaw_godzine(int g, int m);		//ustawianie godziny (godzina, minuty)
	bool przesun_date_o(int r, int m, int t, int d);//przesuwanie daty o zadana liczbe lat, miesiecy, tygodni, dni
	bool operator==(Data & data);			//operator porownujacy obiekty
	friend ostream & operator<<(ostream & os, const Data & data);		//wypisywanie daty
};

#endif
