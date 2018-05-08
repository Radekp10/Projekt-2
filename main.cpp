//testowanie klasy terminarz

#include <iostream>
#include <string>
#include "data.h"
#include "zdarzenie.h"
#include "terminarz.h"

int main()
{
	using namespace std;

	Terminarz T1;

	Zdarzenie zd0("matma");
	Zdarzenie zd1("fiza");
	Zdarzenie zd2("ang");
	Zdarzenie zd3("fo");
	Zdarzenie zd4("costam");

	//Zdarzenie zd0,zd1,zd2,zd3,zd4;


	//zd0.ustaw(2018,11,5);
	zd1.ustawdate(2018,5,5);
	zd2.ustawdate(2018,5,6);
	zd3.ustawdate(2018,5,7);
	zd4.ustawdate(2018,5,13);


	//zd0.ustawgodzine(12,30);
	zd1.ustawgodzine(9,6);
	zd2.ustawgodzine(1,0);
	zd3.ustawgodzine(9,6);
	zd4.ustawgodzine(7,21);



	//zd1.przesun_date_o(0, 2, 0);
	//zd2.przesun_date_o(0, -38, 0);
	//zd3.przesun_date_o(0, -48, 1);
	//zd4.przesun_date_o(0, -47, 0);


	T1.dodaj_zdarzenie(zd0);
	T1.dodaj_zdarzenie(zd1);
	T1.dodaj_zdarzenie(zd2);
	T1.dodaj_zdarzenie(zd3);
	T1.dodaj_zdarzenie(zd4);

	cout << T1;


	T1.przesun_zdarzenie(2,1,2,2,3,14);
	T1.usun_zdarzenie(zd0);
	T1.usun_zdarzenie(zd1);

	cout << T1;

	

	//cout << T1;

	//cout << zd1 << zd2 << zd3 << zd4 << zd5;

	/*if (zd2==zd4) cout <<"EXXXXXTRA";
	else cout << "SZKODA";*/	

	return 0;
}