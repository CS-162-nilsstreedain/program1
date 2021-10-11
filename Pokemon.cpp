//
//  Pokemon.cpp
//  Program 1
//
//  Created by Nils Streedain on 10/9/21.
//

#include "Pokemon.h"

Pokemon::Pokemon() {
	dex_num = 0;
	name = "";
	type = "";
	moves = new std::string[3];
	for (int i = 0; i < 4; i++)
		moves[i] = "";
}

Pokemon::Pokemon(int dex_num, std::string name, std::string type, std::string* moves) {
	this -> dex_num = dex_num;
	this -> name = name;
	this -> type = type;
	this -> moves = moves;
}

//Pokemon::~Pokemon() {
//	delete [] moves;
//}

void Pokemon::print() {
	std::cout << "Pokédex Number: " << dex_num << "\nName: " << name << "\nType: " << type << "\nMoves:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << "\t" << moves[i] << std::endl;
}

int Pokemon::getDexNum() {
	return dex_num;
}

std::string Pokemon::getName() {
	return name;
}

std::string Pokemon::getType() {
	return type;
}
