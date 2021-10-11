//
//  main.cpp
//  Program 1
//
//  Created by Nils Streedain on 10/9/21.
//

#include <iostream>
#include "Pokedex.h"
#include "Pokemon.h"

int main(int argc, const char * argv[]) {
	std::string moves[4] = {"Growl", "Tackle", "Leech Seed", "Vine Whip"};
	Pokedex pokedex;
	pokedex.addPokemon(1, "Bulbasaur", "Grass", moves);
	
	bool quit = false;
	
	while (!quit) {
		int option;
		std::cout << "Options:\n"
						"1: Search by Pokédex Number\n"
						"2: Search by name\n"
						"3: Search by type\n"
						"4: Add new Pokémon\n"
						"5: Quit" << std::endl;
		std::cin >> option;
		
		switch (option) {
			case 1: {
				int dex_num;
				std::cout << "What Pokédex number would you like to search for?" << std::endl;
				std::cin >> dex_num;
				pokedex.searchDex(dex_num) -> print();
				break;
			}
			case 2: {
				std::string name;
				std::cout << "What Pokémon name would you like to search for?" << std::endl;
				std::cin >> name;
				pokedex.searchName(name) -> print();
				break;
			}
			case 3: {
				std::string type;
				std::cout << "What Pokémon type would you like to search for?" << std::endl;
				std::cin >> type;
				pokedex.searchType(type) -> print();
				break;
			}
			case 4: {
				int dex_num;
				std::string name, type;
//				std::string* moves[4];
				
				std::cout << "What is the Pokédex Number for this Pokémon?" << std::endl;
				std::cin >> dex_num;
				
				std::cout << "What is the name of this Pokémon?" << std::endl;
				std::cin >> name;
				
				std::cout << "What is the type for this Pokémon?" << std::endl;
				std::cin >> type;
				
//				std::cout << "What is a move for this Pokémon?" << std::endl;
//				std::cin >> moves[4];
				
				
				break;
			}
			case 5: {
				quit = true;
				break;
			}
			default:
				break;
		}
	}
	
	return 0;
}
