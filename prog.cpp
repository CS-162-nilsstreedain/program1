/*********************************************************************
 ** Program Filename:   prog.cpp
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  Main driver file for Pokédex program.
 ** Input:  filename
 ** Output:  Command Line/Output File
 *********************************************************************/
#include <fstream>
#include "pokedex.h"
 
/*********************************************************************
 ** Function: main()
 ** Description: Reads a file to build a Pokédex object, then asks the user what to do with said object.
 ** Parameters: int argc, const char * argv[]
 ** Pre-Conditions: A filename must be provided as an argument.
 ** Post-Conditions: The file will be parsed into an object and information may be output to the command line or another file.
 *********************************************************************/
int main(int argc, const char * argv[]) {
	// Make sure user has provided a cl arg and open fstream with said arg
	if (argc == 2) {
		std::ifstream file(argv[1]);
		
		// Check if file is open, then parse data into Pokédex
		if (file.is_open()) {
			int numPokemon, currentDex;
			std::string currentName, currentType, currentMoves[4];
			
			file >> numPokemon;
			pokedex pokedex(numPokemon, argv[1]);
			
			// While not at end of file, parse data for each Pokémon being added
			while (!file.eof()) {
				file >> currentDex;
				file >> currentName;
				file >> currentType;
				for (int i = 0; i < 4; i++)
					file >> currentMoves[i];
				
				pokedex.addPokemon(currentDex, currentName, currentType, currentMoves);
			}
			
			// When finished parsing, close file and ask user what to do.
			file.close();
			pokedex.askWhatToDo();
		} else {
			std::cout << "\033[31m" << "Error: File not opened" << "\033[0m" << std::endl;
		}
	} else {
		std::cout << "\033[31m" << "Error: Invalid Command Line Arguments, please provide the filename." << "\033[0m" << std::endl;
	}
	
	return 0;
}
