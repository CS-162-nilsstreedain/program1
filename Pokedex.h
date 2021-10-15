/*********************************************************************
 ** Program Filename:   Pokedex.h
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  Header file for Pokédex class
 *********************************************************************/

#ifndef Pokedex_h
#define Pokedex_h

#include <iostream>
#include <fstream>
#include "Pokemon.h"

class Pokedex {
	int num_pokemon;
	int maxSize;
	Pokemon_h::Pokemon* dex;
	std::string filename;
	
	void printError(std::string);
	int askForInt(std::string);
	std::string askForString(std::string);
	std::string askAboutOutput();
	
	void searchDex();
	void searchName();
	void searchType();
	
	void resizeDex();
	void clAddPokemon();
public:
	Pokedex();
	Pokedex(int, std::string);
	~Pokedex();
	
	void addPokemon(int, std::string, std::string, std::string*);
	void askWhatToDo();
};

#endif /* Pokedex_h */
