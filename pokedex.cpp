/*********************************************************************
 ** Program Filename:   pokedex.cpp
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  C++ file for Pokédex class. Creates a Pokédex object and provides various functions to use with said class.
 *********************************************************************/

#include "pokedex.h"

/*********************************************************************
 ** Function: pokedex()
 ** Description: Default constructor for the pokedex object. Contains no pokemonpokemon at start but has an array size of 8 for efficiency reasons.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A pokedex object will be created containing no pokemonpokemon.
 *********************************************************************/
pokedex::pokedex() {
	num_pokemon = 0;
	maxSize = 8;
	dex = new pokemon_h::pokemon[maxSize];
	filename = "";
}

/*********************************************************************
 ** Function: pokedex()
 ** Description: Paramaterized constructor for making a pokedex object meant to hold a certain number of pokemonpokemon.
 ** Parameters: int num_pokemon
 ** Pre-Conditions: The number of pokemonpokemon to allocate space for must be provided as an argument.
 ** Post-Conditions: A pokedex object of a certain size will be created, containing no pokemonpokemon.
 *********************************************************************/
pokedex::pokedex(int num_pokemon, std::string filename) {
	this -> num_pokemon = 0;
	maxSize = num_pokemon * 2;
	dex = new pokemon_h::pokemon[maxSize];
	this -> filename = filename;
}

/*********************************************************************
 ** Function: ~pokedex()
 ** Description: Default destructor for the pokedex class. Deletes the dynamic array of pokemonpokemon created in the constructors.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: pokedex object called on will be destructed.
 *********************************************************************/
pokedex::~pokedex() {
	delete[] dex;
}

/*********************************************************************
 ** Function: pokedex()
 ** Description: Copy constructor for the pokedex class. Perfoms a deep copy on an old pokedex into a new pokedex.
 ** Parameters: const pokedex& old_pokedex
 ** Pre-Conditions: N/A
 ** Post-Conditions: pokedex object called on will be copied into new pokedex.
 *********************************************************************/
pokedex::pokedex(const pokedex& old_pokedex) {
	num_pokemon = old_pokedex.num_pokemon;
	maxSize = old_pokedex.maxSize;
	for (int i = 0; i < num_pokemon; i++)
		dex[i] = old_pokedex.dex[i];
	filename = old_pokedex.filename;
}

/*********************************************************************
 ** Function: pokedex()
 ** Description: Assignment Operator Overload for the pokedex class. Perfoms a deep copy on an old pokedex into a new pokedex.
 ** Parameters: const pokedex& old_pokedex
 ** Pre-Conditions: N/A
 ** Post-Conditions: pokedex object called on will be copied into new pokedex and will be returned.
 *********************************************************************/
pokedex& pokedex::operator= (const pokedex& old_pokedex) {
	num_pokemon = old_pokedex.num_pokemon;
	maxSize = old_pokedex.maxSize;
	for (int i = 0; i < num_pokemon; i++)
		dex[i] = old_pokedex.dex[i];
	filename = old_pokedex.filename;
	
	return *this;
}

/*********************************************************************
 ** Function: printError()
 ** Description: Prints a red color formatted string to the console for easier reading.
 ** Parameters: std::string error
 ** Pre-Conditions: A string containg an error message must be provided as an argument.
 ** Post-Conditions: The error message will be printed red in the console.
 *********************************************************************/
void pokedex::printError(std::string error) const {
	std::cout << "\033[31m" << error << "\033[0m" << std::endl;
}

/*********************************************************************
 ** Function: askForInt()
 ** Description: Asks the user to input an int with a specified message in the console.
 ** Parameters: std::string request
 ** Pre-Conditions: A string containg the messgae must be provided as an argument.
 ** Post-Conditions: The message will be printed to the console and a verified input will be returned.
 *********************************************************************/
int pokedex::askForInt(std::string request) const {
	std::cout << request << std::endl;
	int num;
	while (!(std::cin >> num)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printError("Error: Not a valid option, please type an integer.");
	}
	
	return num;
}

/*********************************************************************
 ** Function: askForString()
 ** Description: Asks the user to input a string with a specified message in the console.
 ** Parameters: std::string request
 ** Pre-Conditions: A string containg the messgae must be provided as an argument.
 ** Post-Conditions: The message will be printed to the console and a verified input will be returned.
 *********************************************************************/
std::string pokedex::askForString(std::string request) const {
	std::cout << request << std::endl;
	std::string str;
	std::cin >> str;
	
	return str;
}

/*********************************************************************
 ** Function: askAboutOutput()
 ** Description: Asks the user if they would like the output to be to the console or to a file, then asks what file to store the output in.
 ** Parameters: N/A
 ** Pre-Conditions: The user must select an output option and a filename in the console.
 ** Post-Conditions: The output will be selected and the filename will have been chosen if applicable.
 *********************************************************************/
std::string pokedex::askAboutOutput() const {
	int printORfile = askForInt( "Would you like this to be output to the command line(1) or a file(2)?");
	
	std::string filename = "";
	if (printORfile == 2)
		filename = askForString("Type the name of the file where you want the output stored.");
	
	return filename;
}

/*********************************************************************
 ** Function: searchDex()
 ** Description: Loops over every pokemonpokemon in the pokedex until one with the correct pokedex number is found.
 ** Parameters: N/A
 ** Pre-Conditions: The user must provide a pokedex to search for in the console.
 ** Post-Conditions: If a pokemonpokemon has that pokedex number, it will be printed to the console or saved to a file.
 *********************************************************************/
void pokedex::searchDex() const {
	int dex_num = askForInt("What Pokédex number would you like to search for?");
	std::string filename = askAboutOutput();
	
	for (int i = 0; i < num_pokemon; i++) {
		if (dex[i].getDexNum() == dex_num) {
			dex[i].output(filename);
			return;
		}
	}
	printError("Error: No Pokémon exists with that Pokédex number.");
}

/*********************************************************************
 ** Function: searchName()
 ** Description: Loops over every pokemonpokemon in the Pokedex until one with the correct name is found.
 ** Parameters: N/A
 ** Pre-Conditions: The user must provide a name to search for in the console.
 ** Post-Conditions: If a pokemonpokemon has that name, it will be printed to the console or saved to a file.
 *********************************************************************/
void pokedex::searchName() const {
	std::string name = askForString("What Pokémon name would you like to search for?");
	std::string filename = askAboutOutput();
	
	for (int i = 0; i < num_pokemon; i++) {
		if (dex[i].getName() == name) {
			dex[i].output(filename);
			return;
		}
	}
	printError("Error: No Pokémon exists with that name.");
}

/*********************************************************************
 ** Function: searchType()
 ** Description: Loops over every pokemonpokemon in the Pokedex and prints all with the correct type.
 ** Parameters: N/A
 ** Pre-Conditions: The user must provide a type to search for in the console.
 ** Post-Conditions: If a pokemonpokemon has that type, it will be printed to the console or saved to a file.
 *********************************************************************/
void pokedex::searchType() const {
	std::string type = askForString("What Pokémon type would you like to search for?");
	std::string filename = askAboutOutput();
	
	bool foundType = false;
	for (int i = 0; i < num_pokemon; i++){
		if (dex[i].getType() == type) {
			dex[i].output(filename);
			foundType = true;
		}
	}
	if (!foundType)
		printError("Error: No Pokémon exists with that type.");
}

/*********************************************************************
 ** Function: resizeDex()
 ** Description: Creates a new, larger pokemon array and copies the old array contents here.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A larger pokemon array will be created.
 *********************************************************************/
void pokedex::resizeDex() {
	if (num_pokemon + 1 > maxSize) {
		// Creates a new Pokémon array with the larger size
		maxSize = maxSize * 2;
		pokemon_h::pokemon* new_dex = new pokemon_h::pokemon[maxSize];
		
		// Copies old pokemon array to new pokemon array
		for (int i = 0; i < num_pokemon; i++)
			new_dex[i] = dex[i];
		
		// Sets num_pokemon to the new size, deletes old array, replaces old array with new array
		delete[] dex;
		dex = new_dex;
	}
}

/*********************************************************************
 ** Function: clAddpokemon()
 ** Description: Adds pokemon to the pokedex object and input through the console using the addPokemon() function.
 ** Parameters: N/A
 ** Pre-Conditions: The user must provide pokemon details through the console.
 ** Post-Conditions: A new pokemon will be added to the Pokedex object and input file
 *********************************************************************/
void pokedex::clAddPokemon() {
	int dex_num = askForInt("Enter the Pokédex Number for this Pokémon.");
	std::string name = askForString("Enter the name of this Pokémon.");
	std::string type = askForString("Enter the type for this Pokémon.");
	
	std::string moves[4];
	std::cout << "Enter the four moves this Pokémon, separated by spaces." << std::endl;
	std::cin >> moves[0] >> moves[1] >> moves[2] >> moves[3];
	
	this -> addPokemon(dex_num, name, type, moves);
}

/*********************************************************************
 ** Function: addpokemon()
 ** Description: Adds pokemon to the pokedex object
 ** Parameters: int dex_num, std::string name, std::string type, std::string* moves
 ** Pre-Conditions: Arguments must be provided to construct the pokemon
 ** Post-Conditions: A new pokemon will be added to the Pokedex object
 *********************************************************************/
void pokedex::addPokemon(int dex_num, std::string name, std::string type, std::string* moves) {
	pokemon_h::pokemon pokemon(dex_num, name, type, moves);
	
	// Resizes Pokédex when it is not large enough to fit current Pokémon
	resizeDex();
	
	// Adds Pokémon to its index in the Pokédex
	dex[num_pokemon] = pokemon;
	num_pokemon++;
}

/*********************************************************************
 ** Function: askWhatToDo()
 ** Description: Gives the user options on what to do next after the pokedex object has been created.
 ** Parameters: N/A
 ** Pre-Conditions: User must select options through the console
 ** Post-Conditions: A pokemon with certain attributes will be searched for in the pokedex, or a pokemon will be added to the pokedex, or the program will end.
 *********************************************************************/
void pokedex::askWhatToDo() {
	bool quit = false;
	
	while (!quit) {
		switch (askForInt("Options:\n"
						  "1: Search by Pokédex Number\n"
						  "2: Search by name\n"
						  "3: Search by type\n"
						  "4: Add new Pokémon\n"
						  "5: Quit")) {
			case 1:
				this -> searchDex();
				break;
			case 2:
				this -> searchName();
				break;
			case 3:
				this -> searchType();
				break;
			case 4:
				this -> clAddPokemon();
				break;
			case 5:
				quit = true;
				break;
			default:
				printError("Error: Not a valid option, please type an integer between 1-5.");
				break;
		}
	}
}
