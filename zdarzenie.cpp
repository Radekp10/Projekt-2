//metody klasy Zdarzenie

#include <string>
//#include <cmath>
#include "zdarzenie.h"
#include "data.h"


Zdarzenie::Zdarzenie()						//konstruktor domyslny
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zdarzenie::Zdarzenie(const char * s)				//inicjalizacja napisem
{
	string nowy(s);
	opis = nowy;
	Data data;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zdarzenie::~Zdarzenie()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::ustawdate(int r, int m, int d)		//ustawianie daty dla zdarzenia
{
	if ((data.ustaw_date(r,m,d))==true)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::ustawgodzine(int g, int m)			//ustawianie godziny dla zdarzenia
{
	if ((data.ustaw_godzine(g,m))==true)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::przesundate_o(int r, int m, int t, int d)	//przesuwanie daty o zadana liczbe lat, miesiecy, tygodni, dni
{
	if (data.przesun_date_o(r,m,t,d)==true)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::przesun_godzine_o(int g)		//przesuwanie daty o zadana liczbe godzin
{
	data.godzina+=g;

	
	while (data.godzina>23)				//jesli przesuniecie godziny powoduje zmiane dnia do przodu
	{
		if (przesundate_o(0,0,0,1)==true)	//przesuwamy date o 1 dzien do przodu
			data.godzina-=24;		//godzine pomniejszamy o 1 dobe
		else 
			return false;
	}

	while (data.godzina<0)				//jesli przesuniecie godziny powoduje zmiane dnia do tylu
	{
		if (przesundate_o(0,0,0,-1)==true)	//przesuwamy date o 1 dzien do tylu
			data.godzina+=24;		//godzine pomniejszamy o 24 godziny
		else 
			return false;
	}
	
	return true;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::operator==(Zdarzenie & zdarzenie)		//porownywanie obiektow klasy Zdarzenie
{
	if ((opis==zdarzenie.opis) && (data==zdarzenie.data))	//porownanie opisu i daty
		return true;
	else return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Zdarzenie & zdarzenie)		//wypisanie obiektu
{
	os << zdarzenie.data << "\n  "; 
	os << zdarzenie.opis << "\n\n";
	return os;
}
