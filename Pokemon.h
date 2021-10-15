/*********************************************************************
 ** Program Filename:   Pokemon.h
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  Header file for Pokémon class
 *********************************************************************/

#ifndef Pokemon_h
#define Pokemon_h

#include <iostream>

class Pokemon {
	int dex_num;
	std::string name;
	std::string type;
	std::string moves[4];
public:
	Pokemon();
	Pokemon(int, std::string, std::string, std::string*);
	
	void output(std::string);
	std::string to_string();
	
	int getDexNum();
	std::string getName();
	std::string getType();
};

#endif /* Pokemon_h */
