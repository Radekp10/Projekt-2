//metody klasy Data

#include <ctime>
#include <cmath>
#include <string>
#include "data.h"



Data::Data()
{
	time_t t;
	time (&t);						//pobranie aktualnego czasu kalendarzowego
	tm * teraz = localtime(&t);				//zamiana czasu kalendarzowego na lokalny
	rok=teraz->tm_year+1900;				//lata sa liczone od 1900 roku, dlatego trzeba dodac te liczbe
	if (((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0))	//sprawdzenie, czy rok jest przestepny
		czy_przestepny=1;
	else
		czy_przestepny=0;
	miesiac=teraz->tm_mon+1;				//miesiace sa numerowane 0-11, wiec zwiekszamy indeks o 1
	dzien=teraz->tm_mday;
	dzien_tygodnia=teraz->tm_wday;				//niedziela=0, poniedzialek=1, itd.
	godzina=teraz->tm_hour;
	minuta=teraz->tm_min;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Data::~Data()						//destruktor
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Data::ustaw_date(int r, int m, int d)
{
	if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))	//ustalenie, czy podany rok jest przestepny
		czy_przestepny=1;
	else
		czy_przestepny=0;

	if (r<0 || m<1 || m>12 || d<1 || d>31)
		return false;
	else if ((m==4 || m==6 || m==9 || m==11) && (d==31))	//cztery miesiace 30-dniowe
		return false;
	else if (((m==2) && (d==31)) || ((m==2) && (d==30)))	//luty nie moze miec ani 31 ani 30 dni
		return false;
	else if ((m==2) && (czy_przestepny==0) && (d==29))	//luty w roku nieprzestepnym nie moze miec 29 dni
		return false;
	else
	{
		rok=r;			//ustawienie roku
		miesiac=m;		//ustawienie miesiaca
		dzien=d;		//ustawienia dnia miesiaca
	}

	time_t t;
	time (&t);				//pobranie czasu kalendarzowego
	tm * dat = localtime(&t);		//zamiana czasu kalendarzowego na lokalny
	dat->tm_year=rok-1900;
	dat->tm_mon=miesiac-1;
	dat->tm_mday=dzien;
	mktime(dat);				//konwersja na czas kalendarzowy

	dzien_tygodnia=dat->tm_wday;		//przyporzadkowania dnia tygodnia wybranej dacie

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Data::ustaw_godzine(int g, int m)
{
	if (g<0 || g>24 || m<0 || m>59)		//jesli godzina poza zakresem to niepoprawne dane
		return false;
	else
	{
		if (g==24)			//godzine 24 zapiszemy jako godzina 0
			godzina=0;
		else
			godzina=g;
		minuta=m;
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Data::przesun_date_o(int r, int m, int t, int d)	//przesuwanie daty o zadana liczbe lat, miesiecy, tygodni, dni
{
	r+=rok;							//modyfikacja roku


	r+=floor(m/12);						//liczbe m rozbijamy na liczbe pelnych lat...
	if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))	//sprawdzenie, czy nowy rok jest przestepny
		czy_przestepny=1;
	else
		czy_przestepny=0;

	m=miesiac+m%12;						//...i pozostala liczbe miesiecy
	if (m>12)						//jesli nadal m bedzie wieksze od 12
	{
		m-=12;						//to korygujemy liczbe miesiecy
		r+=1;						//i przechodzimy do kolejnego roku
		if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))	//sprawdzenie, czy nowy rok jest przestepny
			czy_przestepny=1;
		else
			czy_przestepny=0;

	}
	if (m<1)						//jesli liczba m ujemna (odjelismy wiecej miesiecy niz numer miesiaca przed odjeciem)
	{
		m+=12;						//to korygujemy liczbe miesiecy
		r-=1;						//i cofamy sie do poprzedniego roku
		if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))	//sprawdzenie, czy nowy rok jest przestepny
			czy_przestepny=1;
		else
			czy_przestepny=0;
	}	
	
								//najpierw ustalamy, o ile dni bedziemy przesuwac
	d+=dzien;
	d+=t*7;							//tygodnie przeliczamy na dni
	

	//przesuniecie daty do tylu wychodzace poza dany miesiac
	while (d<=0)						//przesuniecia bedziemy wykonywac dopoki liczba dni miesiaca bedzie niedodatnia
	{
		if ((m-1)==1 || (m-1)==3 || (m-1)==5 || (m-1)==7 || (m-1)==8 || (m-1)==10)	//jesli luty, kwiec., czerw., sierp., wrzes. lub list.
		{
			m--;								//przejscie do poprzedniego miesiaca
			d+=31;								//i poprawienie dnia miesiaca
		}

		if ((m-1)==0)								//jesli styczen to przesuwamy na grudzien:
		{
			r--;								//przejscie do poprzedniego roku
			if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))		//sprawdzenie, czy rok jest przestepny
				czy_przestepny=1;
			else
				czy_przestepny=0;
			m=12;								//ustawienie grudnia
			d+=31;								//i poprawienie dnia miesiaca
		}
		
		if ((m-1)==4 || (m-1)==6 || (m-1)==9 || (m-1)==11)			//jesli maj, lipiec, pazdziernik lub grudzien
		{
			m--;								//przejscie do poprzedniego miesiaca
			d+=30;								//i poprawienie dnia miesiaca
		}

		if (((m-1)==2) && (czy_przestepny==1))					//jesli marzec w roku przestepnym
		{
			m--;								//przejscie do lutego
			d+=29;								//i poprawienie dnia miesiaca
		}

		if (((m-1)==2) && (czy_przestepny==0))					//jesli marzec w roku nieprzestepnym
		{
			m--;								//przejscie do lutego
			d+=28;								//i poprawienie dnia miesiaca
		}
	}
	


	//przesuniecie daty do przodu wychodzace ponad limit dni miesiaca
	while ( ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d>31))
	|| ((m==4 || m==6 || m==9 || m==11) && (d>30))
	|| ((m==2) && (czy_przestepny==1) && (d>29))
	|| ((m==2) && (czy_przestepny==0) && (d>28)) )
	{
					
		if ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d>31))		//jesli dla miesiecy 31-dniowe mamy wiecej niz 31 dni
		{
			if (m<12)
			{
				m++;								//przejscie do kolejnego miesiaca
				d-=31;								//zmniejszenie liczby d o licznosc dni opuszczanego miesiaca
			}
			if (m==12)								//jesli mamy grudzien
			{
				r++;								//przejscie do kolejnego roku
				if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0))		//sprawdzenie, czy rok jest przestepny
					czy_przestepny=1;
				else
					czy_przestepny=0;
				m=1;								//ustawiamy styczen
				d-=31;								//zmniejszenie liczby d o liczbe dni grudnia
			}
		}

		if ((m==4 || m==6 || m==9 || m==11) && (d>30))					//jesli dla miesiecy 30-dniowych mamy wiecej niz 30 dni
		{
			m++;
			d-=30;
		}

		if ((m==2) && (czy_przestepny==1) && (d>29))				//jesli dla lutego z roku przestepnego mamy wiecej niz 29 dni
		{
			m++;
			d-=29;
		}

		if ((m==2) && (czy_przestepny==0) && (d>28))				//jesli dla lutego z roku zwyklego mamy wiecej niz 28 dni
		{
			m++;
			d-=28;
		}

	}

	
	
	if ((ustaw_date(r,m,d))==true)							//ustawienie daty dla wyznaczonych wartosci
		return true;
	else
		return false;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Data::operator==(Data & data)
{										//porownujemy skladowe rok, miesiac, dzien, godzina, minuta
	if ((rok==data.rok) && (miesiac==data.miesiac) && (dzien==data.dzien)
	&& (godzina==data.godzina) && (minuta==data.minuta))
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Data & data)
{
	if (data.dzien<10)						//jesli dzien miesiaca jest < 10
		os << "0" << data.dzien << ".";		//to dopisujemy zero z przodu dla ujednolicenia zapisu
	else
		os << data.dzien << ".";
	if (data.miesiac<10)					//jesli numer miesiaca jest < 10
		os << "0" << data.miesiac << ".";	//to dopisujemy zero z przodu dla ujednolicenia zapisu
	else
		os << data.miesiac << ".";
	os << data.rok << ", ";

	switch (data.dzien_tygodnia)			//zamiana numeru na napis dzien tygodnia
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
	
	if (data.godzina==24)						//godzine 24 zapiszemy jako 0
		os << ", g.0:";
	else 
		os << ",  g." << data.godzina << ":";			//wypisywanie godziny
	if (data.minuta<10)						//i minut
		os << "0" << data.minuta;
	else
		os << data.minuta;
	return os;
}
