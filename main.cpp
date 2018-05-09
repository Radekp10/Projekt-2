//testowanie klasy terminarz

#include <iostream>
#include <string>
#include "data.h"
#include "zdarzenie.h"
#include "terminarz.h"

int main()
{
	using namespace std;
	
	//utworzenie terminarza
	Terminarz T1;	
				
										
	//utworzenie i inicjalizacja zdarzen
	Zdarzenie zd0("Wyklad: programowanie obiektowe");	
	Zdarzenie zd1("Wyklad: metody numeryczne");
	Zdarzenie zd2("Wyklad: analiza matematyczna");
	Zdarzenie zd3("Wyklad: fizyka ogolna");
	Zdarzenie zd4("Cwiczenie: jezyk angielski");


	//ustawienie daty dla wydarzen
	if (zd0.ustawdate(2018,5,10)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd0 nie powiodlo sie.\n";	
	if (zd1.ustawdate(2018,5,11)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd1 nie powiodlo sie.\n";
	if (zd2.ustawdate(2018,6,6)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd2 nie powiodlo sie.\n";
	if (zd3.ustawdate(2019,5,7)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd3 nie powiodlo sie.\n";
	if (zd4.ustawdate(2018,5,11)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd4 nie powiodlo sie.\n";
	

	//ustawienie godziny dla wydarzen
	if (zd1.ustawgodzine(9,30)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd1 nie powiodlo sie.\n";
	if (zd2.ustawgodzine(11,0)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd2 nie powiodlo sie.\n";
	if (zd3.ustawgodzine(9,6)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd3 nie powiodlo sie.\n";
	if (zd4.ustawgodzine(7,20)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd4 nie powiodlo sie.\n";
								
								

	//przesuniecie daty dla wydarzen
	if (zd1.przesun_date_o(0, 0, 1, 0)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie daty dla zd1 nie powiodlo sie.\n";
	if (zd2.przesun_date_o(0, 0, 2, 3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie daty dla zd2 nie powiodlo sie.\n";
	if (zd3.przesun_date_o(1, 1, 0, 2)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie daty dla zd3 nie powiodlo sie.\n";
	/*if (zd4.przesun_date_o(0, 0, 0, 2)==false) 
		cout <<"NIEPOWODZENIE: Przesuniecie daty dla zd4 nie powiodlo sie.\n";*/


	//przesuniecie godziny dla wydarzen
	if (zd1.przesun_godzine_o(-3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie godziny dla zd1 nie powiodlo sie.\n";
	if (zd2.przesun_godzine_o(1)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie godziny dla zd2 nie powiodlo sie.\n";
	if (zd3.przesun_godzine_o(2)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie godziny dla zd3 nie powiodlo sie.\n";
	/*if (zd4.przesun_godzine_o(6)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie godziny dla zd4 nie powiodlo sie.\n";*/


	//dodanie zdarzen do termianrza
	if (T1.dodaj_zdarzenie(zd0)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd0 do terminarza sie nie powiodlo.\n";
	if (T1.dodaj_zdarzenie(zd1)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd1 do terminarza sie nie powiodlo.\n";
	if (T1.dodaj_zdarzenie(zd2)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd2 do terminarza sie nie powiodlo.\n";
	if (T1.dodaj_zdarzenie(zd3)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd3 do terminarza sie nie powiodlo.\n";
	if (T1.dodaj_zdarzenie(zd4)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd4 do terminarza sie nie powiodlo.\n";
				


	//wypisanie terminarza
	cout << T1;
	
	
	//T1.usun_zdarzenie(zd0);
	//T1.usun_zdarzenie(zd1);
	
	
	//przesuniecie zdarzenia
	if (T1.przesun_zdarzenie(0,1,2,2,3,-3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd0 nie powiodlo sie.\n";	
	if (T1.przesun_zdarzenie(3,2,0,0,3,2)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd3 nie powiodlo sie.\n";			
	
	//usuniecie zdarzenia
	if (T1.usun_zdarzenie(zd2)==false)
		cout <<"NIEPOWODZENIE: Usuniecia zdarzenia zd2 nie powiodlo sie.\n";
	if (T1.usun_zdarzenie(zd1)==false)
		cout <<"NIEPOWODZENIE: Usuniecia zdarzenia zd1 nie powiodlo sie.\n";
		
			
	cout << T1;


	return 0;
}
