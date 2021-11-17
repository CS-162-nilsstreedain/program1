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
#include <limits>
#include "pokemon.h"

class pokedex {
	int num_pokemon;
	int maxSize;
	pokemon_h::pokemon* dex;
	std::string filename;
	
	void printError(std::string) const;
	int askForInt(std::string) const;
	std::string askForString(std::string) const;
	std::string askAboutOutput() const;
	
	void searchDex() const;
	void searchName() const;
	void searchType() const;
	
	void resizeDex();
	void clAddPokemon();
public:
	pokedex();
	pokedex(int, std::string);
	~pokedex();
	pokedex(const pokedex&);
	pokedex& operator= (const pokedex&);
	
	void addPokemon(int, std::string, std::string, std::string*);
	void askWhatToDo();
};

#endif /* Pokedex_h */
