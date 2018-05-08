//klasa reprezentujaca pojedyncze zdarzenie

#ifndef ZDARZENIE_H
#define ZDARZENIE_H

#include <string>
#include "data.h"
using namespace std;


class Zdarzenie
{
private:
	friend class Terminarz;
	Data data;
	string opis;
public:
	Zdarzenie();
	Zdarzenie(const char * s);
	~Zdarzenie();
	bool ustawdate(int r, int m, int d);
	bool ustawgodzine(int h, int m);
	bool przesun_date_o(int r, int m, int t, int d);
	bool przesun_godzine_o(int h);
	bool operator==(Zdarzenie & zdarzenie);
	friend ostream & operator<<(ostream & os,const Zdarzenie & zdarzenie);
};

#endif