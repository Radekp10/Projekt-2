//klasa reprezentujaca pojedyncze zdarzenie

#ifndef ZDARZENIE_H
#define ZDARZENIE_H

#include <string>
#include "data.h"
using namespace std;


class Zdarzenie
{
private:
	friend class Terminarz;						//klasa Zdarzenie ma dostep do prywatnych danych klasy Data
	Data data;
	string opis;								//opis zdarzenia
public:
	Zdarzenie();
	Zdarzenie(const char * s);					//inicjalizacja opisem zdarzenia
	~Zdarzenie();
	bool ustawdate(int r, int m, int d);		//przypisanie daty zdarzeniu
	bool ustawgodzine(int h, int m);			//i godziny
	bool przesun_date_o(int r, int m, int t, int d);	//przesuwanie daty o zadana liczbe lat, miesiecy, dni
	bool przesun_godzine_o(int h);				//przesuwanie godziny o zadana liczbe godzin
	bool operator==(Zdarzenie & zdarzenie);		//operator porownujacy obiekty
	friend ostream & operator<<(ostream & os,const Zdarzenie & zdarzenie);	//wypisywanie zdarzenia
};

#endif
