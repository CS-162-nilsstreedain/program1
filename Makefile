# Program 1 Makefile
CC = g++
exe_file = pokedex
$(exe_file): pokemon.o pokedex.o prog.o
	$(CC) -std=c++11 pokemon.o pokedex.o prog.o -o $(exe_file)
pokemon.o: pokemon.cpp
	$(CC) -std=c++11 -c pokemon.cpp
pokedex.o: pokedex.cpp
	$(CC) -std=c++11 -c pokedex.cpp
prog.o: prog.cpp
	$(CC) -std=c++11 -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file) 
