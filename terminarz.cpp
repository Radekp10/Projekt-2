//metody klasy Terminarz

#include <string>
#include <fstream>
#include "terminarz.h"
#include "zdarzenie.h"
#include "data.h"


Terminarz::Terminarz()
{
	int i;
	for (i=0;i<MAX;i++)				
	{
		Zdarzenie zdarzenie;		//utworzenie zdarzen
		zdarz[i]=zdarzenie;
	}
	liczba_zdarzen=0;				//poczatkowa liczba zdarzen=0
	Data biezaca_data;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Terminarz::~Terminarz()						//destruktor
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::dodaj_zdarzenie(const Zdarzenie & zdarzenie)
{
	if (liczba_zdarzen==MAX-1)				//sprawdzenie czy terminarz nie jest pelny
		return false;
	else
	{
		zdarz[liczba_zdarzen]=zdarzenie;	//dodanie zdarzenia do terminarza
		liczba_zdarzen+=1;					//zwiekszenie liczby zdarzen o 1
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::usun_zdarzenie(Zdarzenie & zdarzenie)
{
	int i,j;
	Zdarzenie zd;									//nowe (puste) zdarzenie, ktore wypelni luke po tym usunietym
	if (liczba_zdarzen>0)
	{
		for (i=0;i<liczba_zdarzen;i++)
			{
			if (zdarz[i]==zdarzenie)				//wyszukanie zdarzenia, ktore chcemy usunac
			{
				for (j=(i+1);j<liczba_zdarzen;j++)
					zdarz[j-1]=zdarz[j];
				zdarz[liczba_zdarzen-1]=zd;			//przestawienie zdarzen
				liczba_zdarzen--;					//zmiejszenie liczby zdarzen w terminarzu o 1
				return true;						//zdarzenie usunieto
			}
			
			//else
			//return false;
			}	
	}
	else
		return false;				//terminarz jest pusty
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::przesun_zdarzenie(int i, int r, int m, int t, int d, int h)
{													//i-indeks zdarzenia
	if (zdarz[i].przesun_date_o(r,m,t,d)==false)	//przesuniecie daty o zadana liczbe lat, miesiecy, tygodni, dni
		return false;
	else if (zdarz[i].przesun_godzine_o(h)==false)	//przesuniecie o zadana liczbe godzin
		return false;
	else
		return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & Terminarz::wypisz_okres(ostream & os, int okres) const	//wypisywanie zdarzen w danym okresie
{
	int i;
	for (i=0;i<liczba_zdarzen;i++)
	{
		if (okres==1)				//zdarzenia w danym dniu
		{
			if ((zdarz[i].data.rok==biezaca_data.rok) && (zdarz[i].data.miesiac==biezaca_data.miesiac)
			&& (zdarz[i].data.dzien==biezaca_data.dzien))
				os << zdarz[i];
		}

		if (okres==2)				//zdarzenia w danym tygodniu
		{
			int dzien1, dzien2, j;
			dzien1=biezaca_data.dzien_tygodnia;
			dzien2=biezaca_data.dzien;
			while (dzien1!=0)		//cofamy sie do niedzieli (indeks 0)
			{
				dzien1--;
				dzien2--;			//i odejmujemy numery dnia miesiaca az zatrzymamy sie na niedzieli
			}
			for (j=dzien2;j<dzien2+7;j++)	//jestesmy wtedy na pocz. tyg. i mozemy szukac zdarzen na ten tydzien
				if ((zdarz[i].data.dzien==j) && (zdarz[i].data.miesiac==biezaca_data.miesiac)
				&& (zdarz[i].data.rok==biezaca_data.rok))
					os << zdarz[i];
		}

		if (okres==3)				//zdarzenia w danym miesiacu
			if (zdarz[i].data.miesiac==biezaca_data.miesiac)
				os << zdarz[i];
	}
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Terminarz & T)
{
	int i;
	os << "\n\t\tTERMINARZ" << "\n";
	os << "Biezaca data: ";
	os << T.biezaca_data << "\n\n";
	for (i=0;i<T.liczba_zdarzen;i++)
		os << T.zdarz[i];
	
	/*os << "  ZDARZENIA na dzien:\n";
	T.wypisz_okres(os,1);
	os << "  ZDARZENIA na tydzien:\n";
	T.wypisz_okres(os,2);
	os << "  ZDARZENIA na miesiac:\n";
	T.wypisz_okres(os,3);*/


													//operacje na plikach
    fstream plik;									
    plik.open( "terminarz.txt", ios::out);			//otwarcie pliku
    if( plik.good() == true )
    {
	//int i;
	plik << "\n\t\tTERMINARZ" << "\n";
	plik << "Biezaca data: ";
	plik << T.biezaca_data << "\n\n";				//wypisanie zdarzen
	/*for (i=0;i<T.liczba_zdarzen;i++)
		plik << T.zdarz[i];*/
	
	plik << "  ZDARZENIA na dzien:\n";
	T.wypisz_okres(plik,1);
	plik << "\n  ZDARZENIA na tydzien:\n";
	T.wypisz_okres(plik,2);
	plik << "\n  ZDARZENIA na miesiac:\n";
	T.wypisz_okres(plik,3);


        plik.close();								//zamkniecie pliku
    }

	return os;
}
