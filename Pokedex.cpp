//
//  Pokedex.cpp
//  Program 1
//
//  Created by Nils Streedain on 10/9/21.
//

#include "Pokedex.h"

Pokedex::Pokedex() {
	trainer = "";
	num_pokemon = 0;
	dex = new Pokemon_h::Pokemon[0];
}

Pokedex::Pokedex(std::string trainer, int num_pokemon, Pokemon_h::Pokemon* dex) {
	this -> trainer = trainer;
	this -> num_pokemon = num_pokemon;
	this -> dex = dex;
}

Pokedex::~Pokedex() {
	delete [] dex;
}

void Pokedex::resizeDex(int size) {
	if (size > num_pokemon) {
		// Creates a new Pokémon array with the larger size
		Pokemon_h::Pokemon* new_dex = new Pokemon_h::Pokemon[size];

		// Copies old pokemon array to new pokemon array
		memcpy(new_dex, dex, num_pokemon * sizeof(Pokemon_h::Pokemon));

		// Sets num_pokemon to the new size, deletes old array, replaces old array with new array
		num_pokemon = size;
		delete [] dex;
		dex = new_dex;
	}
}

void Pokedex::addPokemon(int dex_num, std::string name, std::string type, std::string* moves) {
	Pokemon_h::Pokemon pokemon(dex_num, name, type, moves);
//	Pokemon_h::Pokemon pokemon = new Pokemon_h::Pokemon(dex_num, name, type, moves);

	// Resizes Pokédex if it is not large enough to fit current Pokémon
	resizeDex(dex_num);

	// Adds Pokémon to its index in the Pokédex
	dex[dex_num] = pokemon;
}

Pokemon_h::Pokemon* Pokedex::searchDex(int dex_num) {
	return &dex[dex_num];
}

Pokemon_h::Pokemon* Pokedex::searchName(std::string name) {
	for (int i = 0; i < num_pokemon; i++)
		if (dex[i].getName() == name)
			return &dex[i];
	return nullptr;
}

Pokemon_h::Pokemon* Pokedex::searchType(std::string type) {
	for (int i = 0; i < num_pokemon; i++)
		if (dex[i].getType() == type)
			return &dex[i];
	return nullptr;
}

Pokemon_h::Pokemon* Pokedex::getByDexNum(int index) {
	return &dex[index];
}

int Pokedex::getNumPokemon() {
	return num_pokemon;
}
