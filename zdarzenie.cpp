//metody klasy Zdarzenie

#include <string>
#include <cmath>
#include "zdarzenie.h"
#include "data.h"
using namespace std;


Zdarzenie::Zdarzenie()
{
}

Zdarzenie::Zdarzenie(const char * s)
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

bool Zdarzenie::ustawdate(int r, int m, int d)
{
	if ((data.ustaw_date(r,m,d))==true)
		return true;
	else
		return false;
}




bool Zdarzenie::ustawgodzine(int h, int m)
{
	if ((data.ustaw_godzine(h,m))==true)
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zdarzenie::przesun_date_o(int r, int m, int t, int d)
{
	r+=data.rok;			//modyfikacja roku

	r+=floor(m/12);			//liczbe m rozbijamy na liczbe pelnych lat
	m=data.miesiac+m%12;		//i pozostala liczbe miesiecy
	if (m>12)			//jesli nadal m bedzie wieksze od 12
	{
		m-=12;			//to korygujemy liczbe miesiecy
		r+=1;			//i lat
	}
	if (m<1)			//jesli liczba m ujemna (odjelismy za duzo miesiecy)
	{
		m+=12;			//to kotygujemy liczbe miesiecy
		r-=1;			//i lat
	}
	
	d+=data.dzien;

	d+=t*7;
	
	if ((data.ustaw_date(r,m,d))==true)
		return true;
	else
		return false;
}


bool Zdarzenie::przesun_godzine_o(int h)
{
	data.godzina+=h;
	return true;
}


bool Zdarzenie::operator==(Zdarzenie & zdarzenie)
{
	if ((opis==zdarzenie.opis) && (data==zdarzenie.data))
		return true;
	else return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Zdarzenie & zdarzenie)
{
	os << zdarzenie.data << "\n  "; 
	os << zdarzenie.opis << "\n\n";
	return os;
}

