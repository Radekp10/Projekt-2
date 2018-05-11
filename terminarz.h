//klasa reprezentujaca terminarz

#ifndef TERMINARZ_H
#define TERMINARZ_H

#include <iostream>
#include "data.h"
#include "zdarzenie.h"
using namespace std;


class Terminarz
{
private:
	static const int MAX = 1000;			//max liczba zdarzen, jaka moze przechwywac terminarz
	Zdarzenie zdarz[MAX];				//tablica zawierajaca zdarzenia
	int liczba_zdarzen;				//aktualna liczba zdarzen w terminarzu
	Data biezaca_data;				//terminarz zawiera aktualna date
	ostream & wypisz_okres(ostream & os,int okres) const;		//prywatna metoda pomocnicza do wyswietlania grafiku na okreslony okres
public:
	Terminarz();
	~Terminarz();
	bool dodaj_zdarzenie(const Zdarzenie & zdarzenie);			//dodawanie danego zdarzenia do terminarza
	bool usun_zdarzenie(Zdarzenie & zdarzenie);				//usuwanie danego zdarzenia z terminarza
	bool przesun_zdarzenie(int i, int r, int m, int t, int d, int g);	//przesuwanie zdarzenie w czasie
	bool podroz_w_czasie(int m, int t);					//przeniesienie terminarza w czasie o m miesiecy i t tygodni
	friend ostream & operator<<(ostream & os, const Terminarz & T);		//wypisywanie terminarza
};


#endif
