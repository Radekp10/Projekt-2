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
		Zdarzenie zdarzenie;
		zdarz[i]=zdarzenie;
	}
	liczba_zdarzen=0;
	Data biezaca_data;
}

Terminarz::~Terminarz()
{
}


bool Terminarz::dodaj_zdarzenie(const Zdarzenie & zdarzenie)
{
	if (liczba_zdarzen==MAX-1)
		return false;
	else
	{
		zdarz[liczba_zdarzen]=zdarzenie;
		liczba_zdarzen+=1;
		return true;
	}
}



bool Terminarz::usun_zdarzenie(Zdarzenie & zdarzenie)
{
	int i,j;
	Zdarzenie zd;
	if (liczba_zdarzen>0)
	{
		for (i=0;i<liczba_zdarzen;i++)
			if (zdarz[i]==zdarzenie)
			{
				for (j=(i+1);j<liczba_zdarzen;j++)
					zdarz[j-1]=zdarz[j];
				zdarz[liczba_zdarzen-1]=zd;
				liczba_zdarzen--;
				return true;
			}
			else
				return false;		//zdarzenie nie nalezy do terminarza
	}
	else
		return false;				//terminarz jest pusty
	
}


bool Terminarz::przesun_zdarzenie(int i, int r, int m, int t, int d, int h)
{
	if (zdarz[i].przesun_date_o(r,m,t,d)==false)
		return false;
	else if (zdarz[i].przesun_godzine_o(h)==false)
		return false;
	else
		return false;
}



ostream & Terminarz::wypisz_okres(ostream & os, int okres) const
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
			while (dzien1!=0)		//cofamy sie do poniedzialku
			{
				dzien1--;
				dzien2--;		//i odejmujemy numery dnia miesiaca
			}
			for (j=dzien2;j<dzien2+7;j++)	//jestesmy wtedy na pocz. tyg. i mozemy szukac zdarzen na ten tydzien
				if ((zdarz[i].data.dzien==j) && (zdarz[i].data.miesiac==biezaca_data.miesiac)
				&& (zdarz[i].data.rok==biezaca_data.rok))
					os << zdarz[i];
		}

		if (okres==3)			//zdarzenia w danym miesiacu
			if (zdarz[i].data.miesiac==biezaca_data.miesiac)
				os << zdarz[i];
	}
	return os;
}



ostream & operator<<(ostream & os, const Terminarz & T)
{
	int i;
	os << "\n\t\tTERMINARZ" << "\n";
	os << "Biezaca data: ";
	os << T.biezaca_data << "\n\n";
	for (i=0;i<T.liczba_zdarzen;i++)
		os << T.zdarz[i];
	
	/*os << "  Zdarzenie na dzien:\n";
	T.wypisz_okres(os,1);
	os << "  Zdarzenia na tydzien:\n";
	T.wypisz_okres(os,2);
	os << "  Zdarzenia na miesiac:\n";
	T.wypisz_okres(os,3);*/


	
    fstream plik;
    plik.open( "terminarz.txt", ios::out);
    if( plik.good() == true )
    {
	int i;
	plik << "\n\t\tTERMINARZ" << "\n";
	plik << "Biezaca data: ";
	plik << T.biezaca_data << "\n\n";
	for (i=0;i<T.liczba_zdarzen;i++)
		plik << T.zdarz[i];
	
	/*plik << "  Zdarzenie na dzien:\n";
	T.wypisz_okres(os,1);
	plik << "  Zdarzenia na tydzien:\n";
	T.wypisz_okres(os,2);
	plik << "  Zdarzenia na miesiac:\n";
	T.wypisz_okres(os,3);*/



        plik.close();
    }



	return os;
}