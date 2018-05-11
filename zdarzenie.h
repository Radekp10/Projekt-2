//klasa reprezentujaca pojedyncze zdarzenie

#ifndef ZDARZENIE_H
#define ZDARZENIE_H

#include <string>
#include "data.h"
using namespace std;


class Zdarzenie
{
private:
	Data data;
	string opis;						//opis zdarzenia
	friend class Terminarz;					//klasa Zdarzenie ma dostep do prywatnych danych klasy Data
public:
	Zdarzenie();
	Zdarzenie(const char * s);				//inicjalizacja opisem zdarzenia
	~Zdarzenie();
	bool ustawdate(int r, int m, int d);			//przypisanie daty zdarzeniu
	bool ustawgodzine(int g, int m);			//i godziny
	bool przesundate_o(int r, int m, int t, int d);		//przesuwanie daty o zadana liczbe lat, miesiecy, tygodni, dni
	bool przesun_godzine_o(int g);				//przesuwanie godziny o zadana liczbe godzin
	bool operator==(Zdarzenie & zdarzenie);			//operator porownujacy obiekty
	friend ostream & operator<<(ostream & os,const Zdarzenie & zdarzenie);	//wypisywanie zdarzenia
};

#endif
