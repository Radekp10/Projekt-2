//testowanie klasy terminarz

//Wyjasnienie: w oknie konsoli wyswietlany jest caly terminarz, natomiast
//terminarz na dany dzien, tydzien i miesiac jest zapisywany do pliku 'terminarz.txt'


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
	Zdarzenie zd5("Wyklad: podstawy techniki cyfrowej");


	//ustawienie daty dla wydarzen
	if (zd3.ustawdate(2018,5,12)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd3 nie powiodlo sie.\n";
	if (zd0.ustawdate(2018,5,15)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd0 nie powiodlo sie.\n";	
	if (zd4.ustawdate(2018,5,16)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd4 nie powiodlo sie.\n";
	if (zd1.ustawdate(2018,5,21)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd1 nie powiodlo sie.\n";
	if (zd5.ustawdate(2020,2,20)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd5 nie powiodlo sie.\n";
	if (zd2.ustawdate(2018,5,24)==false)
		cout <<"NIEPOWODZENIE: Ustawienie daty dla zd2 nie powiodlo sie.\n";

	

	//ustawienie godziny dla wydarzen
	if (zd0.ustawgodzine(12,30)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd0 nie powiodlo sie.\n";
	if (zd1.ustawgodzine(9,30)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd1 nie powiodlo sie.\n";
	if (zd2.ustawgodzine(11,0)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd2 nie powiodlo sie.\n";
	if (zd3.ustawgodzine(9,16)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd3 nie powiodlo sie.\n";
	if (zd4.ustawgodzine(14,20)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd4 nie powiodlo sie.\n";
	if (zd5.ustawgodzine(8,45)==false)
		cout <<"NIEPOWODZENIE: Ustawienie godziny dla zd5 nie powiodlo sie.\n";

		
						
	//dodanie zdarzen do terminarza
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
	if (T1.dodaj_zdarzenie(zd5)==false)
		cout <<"NIEPOWODZENIE: Dodanie zdarzenia zd5 do terminarza sie nie powiodlo.\n";

	

	//wypisanie poczatkowego terminarza	
	cout << T1;	
			
			
	//usuniecie zdarzenia
	if (T1.usun_zdarzenie(zd0)==false)
		cout <<"NIEPOWODZENIE: Usuniecia zdarzenia zd0 nie powiodlo sie.\n";


	//przesuniecie zdarzen
	if (T1.przesun_zdarzenie(0,0,0,0,8,-3)==false)						//parametry: (nr_zdarz,r,m,t,d,g)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd1 nie powiodlo sie.\n";	
	if (T1.przesun_zdarzenie(1,0,0,1,4,-3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd2 nie powiodlo sie.\n";
	if (T1.przesun_zdarzenie(2,0,0,3,0,2)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd3 nie powiodlo sie.\n";
	if (T1.przesun_zdarzenie(3,0,0,2,2,3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd4 nie powiodlo sie.\n";
	if (T1.przesun_zdarzenie(4,0,0,0,10,3)==false)
		cout <<"NIEPOWODZENIE: Przesuniecie zdarzenia zd4 nie powiodlo sie.\n";


	//przenosimy sie 3 tygodnie do przodu		
	if (T1.podroz_w_czasie(0,3)==false)
		cout <<"NIEPOWODZENIE: Podroz w czasie nie powiodla sie.\n";


	cout << "\n***** Modyfikacja terminarza: usuniecie pierwszego   *****\n";
	cout << "***** zdarzenia i przesuniecie pozostalych w czasie. *****\n";
	cout << "***** Dla zmiany dla zdarzenia \"Wyklad:podstawy      *****\n";
	cout << "***** techniki cyfrowej\" widoczne jest uwzglednienie *****\n"; 
	cout << "***** roku przestepnego (przesuniecie o 10 dni).     *****\n\n\n";


	//wypisanie terminarza po zmianach
	cout << T1;			//w oknie konsoli wyswietlany jest caly terminarz, natomiast
					//terminarz na dany dzien, tydzien i miesiac jest zapisywany do pliku 'terminarz.txt'
	
	return 0;
}
