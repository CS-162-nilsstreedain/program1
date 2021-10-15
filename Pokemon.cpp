/*********************************************************************
 ** Program Filename:   Pokemon.cpp
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  C++ file for Pokémon class. Creates a Pokédex object and provides various functions to use with said class.
 *********************************************************************/

#include <string>
#include <fstream>
#include "Pokemon.h"

/*********************************************************************
 ** Function: Pokemon()
 ** Description: Default constructor for the Pokemon object. Contains empty Pokemon information
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A new pokemon object will be created with empty contents.
 *********************************************************************/
Pokemon::Pokemon() {
	dex_num = 0;
	name = "";
	type = "";
	for (int i = 0; i < 4; i++)
		moves[i] = "";
}

/*********************************************************************
 ** Function: Pokedex()
 ** Description: Paramaterized constructor for making a pokemon object with specific attributes.
 ** Parameters: int dex_num, std::string name, std::string type, std::string* moves
 ** Pre-Conditions: Pokemon attributes must be provided as arguments
 ** Post-Conditions: A pokemon object with specific attributes will be created.
 *********************************************************************/
Pokemon::Pokemon(int dex_num, std::string name, std::string type, std::string* moves) {
	this -> dex_num = dex_num;
	this -> name = name;
	this -> type = type;
	for (int i = 0; i < 4; i++)
		this -> moves[i] = moves[i];
}

/*********************************************************************
 ** Function: output()
 ** Description: Function for outputing pokemon information to the console or a file depending on if output() was called with a filename or not.
 ** Parameters: std::string filename
 ** Pre-Conditions: A filename may be provided.
 ** Post-Conditions: If a filename was provided, the output is saved to the file, otherwise, it is printed to the console.
 *********************************************************************/
void Pokemon::output(std::string filename) {
	// Creates an output to save or print
	std::string output = to_string();
	
	// Checks if the filname string is empty or not
	if (!(filename.length() > 0)) {
		// If empty, output is printed
		std::cout << output << std::endl;
	} else {
		// Otherwise it is saved to the given file
		std::ofstream file(filename, std::ios::app);
		
		if (file.is_open()) {
			file << output << std::endl;
			file.close();
		} else {
			std::cout << "\033[31m" << "Error: File not opened" << "\033[0m" << std::endl;
		}
	}
}

/*********************************************************************
 ** Function: to_string()
 ** Description: Function for building a string output for a Pokemon.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A string representation of a Pokemon will be output.
 *********************************************************************/
std::string Pokemon::to_string() {
	std::string output = "Pokédex Number: " + std::to_string(dex_num)
	+ "\nName: " + name
	+ "\nType: " + type
	+ "\nMoves:\n";
	for (int i = 0; i < 4; i++)
		output += "\t" + moves[i] + "\n";
	return output;
}

/*********************************************************************
 ** Function: getDexNum()
 ** Description: Function for getting the Pokedex number of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Pokedex number of the pokemon will be returned.
 *********************************************************************/
int Pokemon::getDexNum() {
	return dex_num;
}

/*********************************************************************
 ** Function: getName()
 ** Description: Function for getting the name of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Name of the pokemon will be returned.
 *********************************************************************/
std::string Pokemon::getName() {
	return name;
}

/*********************************************************************
 ** Function: getType()
 ** Description: Function for getting the type of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Type of the pokemon will be returned.
 *********************************************************************/
std::string Pokemon::getType() {
	return type;
}
