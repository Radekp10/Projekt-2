#makefile

__start__: a.out
	./a.out

a.out: main.o terminarz.o data.o zdarzenie.o
	g++ main.o terminarz.o data.o zdarzenie.o

main.o: main.cpp data.h zdarzenie.h terminarz.h
	g++ -c -Wall main.cpp

terminarz.o: terminarz.h zdarzenie.h data.h terminarz.cpp
	g++ -c -Wall terminarz.cpp

data.o: data.h data.cpp
	g++ -c -Wall data.cpp

zdarzenie.o: zdarzenie.h data.h zdarzenie.cpp
	g++ -c -Wall zdarzenie.cpp

clean: 
	rm main.o terminarz.o data.o zdarzenie.o a.out
