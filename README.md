# Pokemon Encyclopedia
## Problem Statement
Professor Oak has been discovering more new Pokemon than he knows what to do with lately. He has hired you to create a Pokemon catalog program that will make gathering new Pokemon data and searching through it easier.
To simplify your task, the Professor has provided you with their current Pokemon information. These come in the form of a text file that contains a list of the currently discovered Pokemon and their moves, all of the information that your program will display.

*Original Pokedex Inspiration:*

https://www.youtube.com/watch?v=p2pk0JEOYvE (Links to an external site.)


## Requirements
### Command Line Argument:
When starting the program, the user will provide one command line argument. The command line argument will be the name of the file that contains the information about Pokemon. If the user does not provide the name of an existing file the program should print out an error message and quit.

### Searching and Printing:
Once the program begins, the user should be prompted with a list of different ways to display the Pokedex information. After the user has chosen an option, they should be asked if they want the information printed to the screen or written to a file. If they choose to write to a file, they should be prompted for a file name. If the file name already exists, the information should be appended to the file. If the file name does not exist, a file should be created and the information should be written to the file. 

#### Available Options:

- Search by dex number: If the user picks this option the program must search through the available Pokemon for one that matches a user entered number. Once found, it should print/write to file that Pokemon's data. If there is no matching Pokemon, the program must print an error message and give them all of the options again.
- Search by name: If the user picks this option the program must search through the available Pokemon for one that matches a user entered name. Once found, it should print/write to file that Pokemon's data. If there is no matching Pokemon, the program must print an error message and give them all of the options again.
- Search by type: If the user picks this option the program must search through the available Pokemon for ones that match a user entered type. Once found, it should print/write to file all of the Pokemon that have that type. If there is no Pokemon with the requested type, the program must print an error message and give them all of the options again.
- Add new Pokemon: If the user picks this option, the program must prompt the user to enter each of the fields for a new Pokemon. The size of the Pokedex will need to dynamically increase to store the new data.
- Quit: The program will exit.
Your program should continue searching and printing/writing until the user chooses to quit. 

### Required Classes:
The following classes are required in your program. They will help organize the information that will be read in (or derived) from the files. You cannot modify, add, or take away any part of the class.

The **Pokedex** class will be used to hold information from the dex.txt file. This class holds information about the Pokedex.

```
class Pokedex {
  string trainer;
  int num_pokemon;
  Pokemon* dex;
};
```

The **Pokemon** class will also be used to read in information from the dex.txt file. This class holds information about a Pokemon.
```
class Pokemon{
  int dex_num;
  string name;
  string type;
  string moves[4]; 
};
```

## Required Input File Format
Your program must accommodate the file formats as specified in this section. The spellbooks.txt file has the following structure. The file information will be provided in sets (corresponding to each spellbook). Each spellbook will be accompanied by a listing of the spells inside.

The dex.txt file will have the following pattern, and an example can be found here (link to text file)   Download here (link to text file) :

```
<total number of Pokemon in file>
<dex number of first Pokemon> <name> <type>
<name of move 1> <name of move 2> <name of move 3> <name of move 4>
<dex number of second Pokemon> <name> <type>
<name of move 1> <name of move 2> <name of move 3> <name of move 4>
<dex number of third Pokemon> <name> <type>
<name of move 1> <name of move 2> <name of move 3> <name of move 4>

etc...
```

## Programming Style/Comments
In your implementation, make sure that you include a program header. Also ensure that you use proper indentation/spacing and include comments! Below is an example header to include. Make sure you review the style guidelines   Download style guidelines for this class, and begin trying to follow them, i.e. don’t align everything on the left or put everything on one line!

```
/******************************************************
** Program: pokedex.cpp
** Author: 
** Date: 
** Description:  
** Input:
** Output:
******************************************************/
```

When you compile your code, it is acceptable to use C++11 functionality in your program. In order to support this, change your Makefile to include the proper flag.
For example, consider the following approach (note the inclusion of **-std=c++11**):

```
g++ -std=c++11 //other flags and parameters
```

In order to submit your homework assignment, you must create a tarred archive that contains your .h, .cpp, and Makefile files. This tar file will be submitted to Canvas. In order to create the tar file, use the following command:

```
tar –cvf assign1.tar pokedex.h pokedex.cpp pokemon.h pokemon.cpp prog.cpp Makefile
```

Note that you are expected to modularize your code into a header file (.h), an implementation file (.cpp), and a driver file (.cpp).

You do not need to submit the txt files. The TA’s will have their own for grading.
