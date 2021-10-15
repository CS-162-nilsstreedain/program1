/*********************************************************************
 ** Program Filename:   pokemon.h
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  Header file for Pokémon class
 *********************************************************************/

#ifndef pokemon_h
#define pokemon_h

#include <iostream>

class pokemon {
	int dex_num;
	std::string name;
	std::string type;
	std::string moves[4];
public:
	pokemon();
	pokemon(int, std::string, std::string, std::string*);
	
	void output(std::string);
	std::string to_string();
	
	int getDexNum();
	std::string getName();
	std::string getType();
};

#endif /* Pokemon_h */
