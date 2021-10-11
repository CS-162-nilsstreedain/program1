//
//  Pokemon.h
//  Program 1
//
//  Created by Nils Streedain on 10/9/21.
//

#ifndef Pokemon_h
#define Pokemon_h

#include <iostream>

class Pokemon {
	int dex_num;
	std::string name;
	std::string type;
	std::string* moves;
public:
	Pokemon();
	Pokemon(int, std::string, std::string, std::string*);
//	~Pokemon();
	
	void print();
	
	int getDexNum();
	std::string getName();
	std::string getType();
};

#endif /* Pokemon_h */
