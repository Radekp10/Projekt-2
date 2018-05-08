//metody klasy Data

#include <ctime>
#include <string>
#include "data.h"


Data::Data()
{
	time_t t;
	time (&t);			//pobranie aktualnego czasu kalendarzowego
	tm * teraz = localtime(&t);	//zamiana czasu kalendarzowego na lokalny
	rok=teraz->tm_year+1900;	//lata sa liczone od 1900 roku, dlatego trzeba dodac te liczbe
	miesiac=teraz->tm_mon+1;	//miesiace sa numerowane 0-11, wiec zwiekszamy indeks o 1
	dzien=teraz->tm_mday;
	dzien_tygodnia=teraz->tm_wday;	//niedziela=0, poniedzialek=1, itd.
	godzina=teraz->tm_hour;
	minuta=teraz->tm_min;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Data::~Data()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Data::ustaw_date(int r, int m, int d)
{
	if (r<0 || m<1 || m>12 || d<1 || d>31)
		return false;
	else if ((m==4 || m==6 || m==9 || m==11) && (d==31))	// cztery miesiace 30-dniowe
		return false;
	else if (((m==2) && (d==31)) || ((m==2) && (d==30)))	//luty na 28/29 dni
		return false;
	else
	{
		rok=r;			//ustawienie roku
		miesiac=m;		//ustawienie miesiaca
		dzien=d;		//ustawienia dnia miesiaca
	}

	time_t t;
	time (&t);			//pobranie czasu kalendarzowego
	tm * dat = localtime(&t);	//zamiana czasu kalendarzowego na lokalny
	dat->tm_year=rok-1900;
	dat->tm_mon=miesiac-1;
	dat->tm_mday=dzien;
	mktime(dat);			//konwersja na czas kalendarzowy

	dzien_tygodnia=dat->tm_wday;	//przyporzadkowania dnia tygodnia wybranej dacie

	return true;
}


bool Data::ustaw_godzine(int h, int m)
{
	if (h<0 || h>24 || m<0 || m>59)	//jesli godzina poza zakresem to niepoprawne dane
		return false;
	else
	{
		if (h==24)		//godzina 24 przyjmujemy za polnoc, czyli godzin 0
			godzina=0;
		else
			godzina=h;
		minuta=m;
		return true;
	}
}


bool Data::operator==(Data & data)
{
	if ((rok==data.rok) && (miesiac==data.miesiac) && (dzien==data.dzien)
	&& (godzina==data.godzina) && (minuta==data.minuta))
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Data & data)
{
	if (data.dzien<10)				//jesli dzien miesiaca jest < 10
		os << "0" << data.dzien << ".";		//to dopisujemy zero z przodu dla ujednolicenia zapisu
	else
		os << data.dzien << ".";
	if (data.miesiac<10)				//jesli numer miesiaca jest < 10
		os << "0" << data.miesiac << ".";	//to dopisujemy zero z przodu dla ujednolicenia zapisu
	else
		os << data.miesiac << ".";
	os << data.rok << ", ";

	switch (data.dzien_tygodnia)
	{
		case 0:
			os << "  Niedziela ";
			break;
		case 1:
			os << "Poniedzialek";
			break;
		case 2:
			os << "   Wtorek   ";
			break;
		case 3:
			os << "   Sroda    ";
			break;
		case 4:
			os << "  Czwartek  ";
			break;
		case 5:
			os << "   Piatek   ";
			break;
		case 6:
			os << "   Sobota   ";
			break;
	}

	//os << "\n ";
	
	if (data.godzina<10)
		os << ",  g." << data.godzina << ":";
	else 
		os << ",  g." << data.godzina << ":";
	if (data.minuta<10)
		os << "0" << data.minuta;
	else
		os << data.minuta;
	return os;
}