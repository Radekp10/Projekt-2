//metody klasy Zdarzenie

#include <string>
#include <cmath>
#include "zdarzenie.h"
#include "data.h"


Zdarzenie::Zdarzenie()								//konstruktor domyslny
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

bool Zdarzenie::ustawgodzine(int h, int m)			//ustawianie godziny dla zdarzenia
{
	if ((data.ustaw_godzine(h,m))==true)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::przesun_date_o(int r, int m, int t, int d)	//przesuwanie daty o zadana liczbe lat, miesiecy, tygodni, dni
{
	r+=data.rok;						//modyfikacja roku

	r+=floor(m/12);						//liczbe m rozbijamy na liczbe pelnych lat
	m=data.miesiac+m%12;				//i pozostala liczbe miesiecy
	if (m>12)							//jesli nadal m bedzie wieksze od 12
	{
		m-=12;							//to korygujemy liczbe miesiecy
		r+=1;							//i lat
	}
	if (m<1)							//jesli liczba m ujemna (odjelismy za duzo miesiecy)
	{
		m+=12;							//to korygujemy liczbe miesiecy
		r-=1;							//i lat
	}
	
	d+=data.dzien;						//modyfikacja dnia miesiaca
	if ((d<0) || (d>31) || ((m==4 || m==6 || m==9 || m==11) && (d==31))
	|| (((m==2) && (d==31)) || ((m==2) && (d==30))))
		return false;

	d+=t*7;								//modyfikacja dnia miesiaca-uwzglednienie przesuniecia w tygodniach
	if ((d<0) || (d>31) || ((m==4 || m==6 || m==9 || m==11) && (d==31))
	|| (((m==2) && (d==31)) || ((m==2) && (d==30))))
		return false;

	
	if ((data.ustaw_date(r,m,d))==true)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::przesun_godzine_o(int h)		//przesuwanie daty o zadana liczbe godzin
{
	data.godzina+=h;
	if (data.godzina<0 || data.godzina>24)
		{
			data.godzina-=h;
			return false;
		}
	else
		return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::operator==(Zdarzenie & zdarzenie)			//porownywanie obiektow klasy Zdarzenie
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
