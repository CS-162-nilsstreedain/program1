//
//  Pokedex.h
//  Program 1
//
//  Created by Nils Streedain on 10/9/21.
//

#ifndef Pokedex_h
#define Pokedex_h

#include <iostream>
#include "Pokemon.h"

class Pokedex {
	std::string trainer;
	int num_pokemon;
	Pokemon_h::Pokemon* dex;
	
	void resizeDex(int);
public:
	Pokedex();
	Pokedex(std::string, int, Pokemon_h::Pokemon*);
	~Pokedex();
	
	void addPokemon(int, std::string, std::string, std::string*);
	
	Pokemon_h::Pokemon* searchDex(int);
	Pokemon_h::Pokemon* searchName(std::string);
	Pokemon_h::Pokemon* searchType(std::string);
	
	Pokemon_h::Pokemon* getByDexNum(int);
	int getNumPokemon();
};

#endif /* Pokedex_h */
