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
		liczba_zdarzen+=1;			//zwiekszenie liczby zdarzen o 1
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::usun_zdarzenie(Zdarzenie & zdarzenie)
{
	int i,j;
	Zdarzenie zd;								//nowe (puste) zdarzenie, ktore wypelni luke po tym usunietym
	if (liczba_zdarzen>0)
	{
		for (i=0;i<liczba_zdarzen;i++)
		{
			if (zdarz[i]==zdarzenie)				//wyszukanie zdarzenia, ktore chcemy usunac
			{
				for (j=(i+1);j<liczba_zdarzen;j++)
					zdarz[j-1]=zdarz[j];			//przestawienie zdarzen
				zdarz[liczba_zdarzen-1]=zd;			
				liczba_zdarzen--;				//zmiejszenie liczby zdarzen w terminarzu o 1
				return true;					//zdarzenie usunieto
			}
		}
		return false;			//nie znaleziono zdarzenia w terminarzu
				
	}
	else
		return false;			//terminarz jest pusty
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::przesun_zdarzenie(int i, int r, int m, int t, int d, int g)
{													//i-indeks zdarzenia
	if (zdarz[i].przesundate_o(r,m,t,d)==false)	//przesuniecie daty o zadana liczbe lat, miesiecy, tygodni, dni
		return false;
	else if (zdarz[i].przesun_godzine_o(g)==false)	//przesuniecie o zadana liczbe godzin
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
			Data dat;			//tworzymy obiekt dat
			dat=biezaca_data;		//i ladujemy do niego biezaca date
			int dzien1;			//zmienna do przechowywania numeru dnia tygodnia
			int j;				//zmienna do obslugi petli
			int k=0;			//zmienna zliczajaca dni w tygodniu przed i po biezacym dniu, max k=7
			dzien1=dat.dzien_tygodnia;
			while (dzien1!=1)					//cofamy sie do poniedzialu (indeks 1)
			{
				dzien1--;					//zmniejszamy numer dnia tygodnia o 1
				dat.przesun_date_o(0,0,0,-1);			//cofamy date o 1 dzien
			}

			while (dat.dzien!=biezaca_data.dzien)			//sprawdzenie dni w tygodniu przed dniem biezacym
			{
				if ((zdarz[i].data.dzien==dat.dzien) && (zdarz[i].data.miesiac==dat.miesiac)
				&& (zdarz[i].data.rok==dat.rok))
					os << zdarz[i];
		
				dat.przesun_date_o(0,0,0,1);
				k++;						//k-ty dzien sprawdzony
			}

			if ((zdarz[i].data.dzien==dat.dzien) && (zdarz[i].data.miesiac==dat.miesiac)		//sprawdzenie biezacego dnia
			&& (zdarz[i].data.rok==dat.rok))
					os << zdarz[i];

			for (j=1;j<=7-k-1;j++)					//sprawdzenie dni w tygodniu po dniu biezacym
			{
				dat.przesun_date_o(0,0,0,1);			//przesuwamy date o 1 dzien do przodu az dojedziemy do konca tygodnia
				if ((zdarz[i].data.dzien==dat.dzien) && (zdarz[i].data.miesiac==dat.miesiac)
				&& (zdarz[i].data.rok==dat.rok))
					os << zdarz[i];
			}
		}

		if (okres==3)				//zdarzenia w danym miesiacu
			if ((zdarz[i].data.miesiac==biezaca_data.miesiac) && (zdarz[i].data.rok==biezaca_data.rok))
				os << zdarz[i];
	}
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Terminarz::podroz_w_czasie(int m, int t)
{
	if (biezaca_data.przesun_date_o(0,m,t,0)==true)		//przenosimy sie w czasie o m miesiecy i t tygodni
		return true;
	else
		return false;
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
		plik << T.biezaca_data << "\n\n";		


		plik << "  ZDARZENIA na dzien:\n";
		T.wypisz_okres(plik,1);				//wypisanie zdarzen na dzien
		plik << "\n\n  ZDARZENIA na tydzien:\n";
		T.wypisz_okres(plik,2);				//wypisanie zdarzen na tydzien
		plik << "\n\n  ZDARZENIA na miesiac:\n";
		T.wypisz_okres(plik,3);				//wypisanie zdarzen na miesiac


        plik.close();						//zamkniecie pliku
	}

	return os;
}
