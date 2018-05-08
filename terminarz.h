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
	static const int MAX = 1000;
	Zdarzenie zdarz[MAX];
	int liczba_zdarzen;
	Data biezaca_data;
	ostream & wypisz_okres(ostream & os,int okres) const;		//prywatna metoda pomocnicza do wyswietlania grafiku na okreslony okres
public:
	Terminarz();
	~Terminarz();
	bool dodaj_zdarzenie(const Zdarzenie & zdarzenie);
	bool usun_zdarzenie(Zdarzenie & zdarzenie);
	bool przesun_zdarzenie(int i, int r, int m, int t, int d, int h);
	friend ostream & operator<<(ostream & os, const Terminarz & T);
};


#endif