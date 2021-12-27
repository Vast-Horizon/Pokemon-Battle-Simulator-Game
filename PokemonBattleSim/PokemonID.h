/*
if the user wants to know more information about a specific Pokemon,
the user can enter a number and this function will call the appropriate function regarding the Pokemon chosen.
*/

#ifndef POKEMONID_H
#define POKEMONID_H

#include <iostream>

class PokemonID {
private:

public:

	void getID(int);

	void torterra() const;
	void charmeleon() const;
	void pikachu() const;
	void squirtle() const;
};
#endif