/*********************************************************************
 ** Program Filename:   pokedex.h
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  Header file for Pokédex class
 *********************************************************************/

#ifndef pokedex_h
#define pokedex_h

#include <iostream>
#include <fstream>
#include "pokemon.h"

class pokedex {
	int num_pokemon;
	int maxSize;
	pokemon_h::pokemon* dex;
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
	pokedex();
	pokedex(int, std::string);
	~pokedex();
	
	void addPokemon(int, std::string, std::string, std::string*);
	void askWhatToDo();
};

#endif /* Pokedex_h */
