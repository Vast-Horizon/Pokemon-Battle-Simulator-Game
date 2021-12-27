#include "PokemonID.h"
#include <iomanip>
/*
if the user wants to know more information about a specific Pokemon, 
the user can enter a number and this function will call the appropriate function regarding the Pokemon chosen.
*/
void PokemonID::getID(int i) {
	if (i == 1)
		torterra();
	else if (i == 2)
		charmeleon();
	else if (i == 3)
		squirtle();
	else if (i == 4)
		pikachu();
}

//Torterra's information
void PokemonID::torterra() const {
	std::cout << "==============================================================" << std::endl;
	std::cout << std::setw(42) << "Pokemon Information" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Name: Torterra" << std::setw(22) << "Num: #389" << std::setw(26) << "Type: Grass/Ground" << std::endl;
	std::cout << "Gender: Female" << std::setw(22) << "Height: 2.2 m" << std::setw(26) << "Weight: 310 kg" << std::endl;
	std::cout << std::endl << std::setw(35) << "Moves" << std::endl;
	std::cout << "Razor Leaf" << std::setw(21) << "Damage:" << std::setw(5) 
		<< -25 << std::setw(21) << "Hit Probability:" << std::setw(5) << 90 << std::endl;
	std::cout << "Earthquake" << std::setw(21) << "Damage:" << std::setw(5) 
		<< -70 << std::setw(21) << "Hit Probability:" << std::setw(5) << 40 << std::endl;
	std::cout << "Synthesis" << std::setw(22) << "Damage:" << std::setw(5) 
		<< +30 	<< std::setw(21) << "Hit Probability:" << std::setw(5) << 65 << std::endl;
	std::cout << "Wood Hammer" << std::setw(20) << "Damage:" << std::setw(5) 
		<< -80 << std::setw(21) << "Hit Probability:" << std::setw(5) << 50 << std::endl;
}

//Charmelon's information
void PokemonID::charmeleon() const {
	std::cout << "==============================================================" << std::endl;
	std::cout << std::setw(42) << "Pokemon Information" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Name: Charmeleon" << std::setw(20) << "Num: #005" << std::setw(26) << "Type: Fire" << std::endl;
	std::cout << "Gender: Male" << std::setw(24) << "Height: 1.1 m" << std::setw(26) << "Weight: 19 kg" << std::endl;
	std::cout << std::endl << std::setw(35) << "Moves" << std::endl;
	std::cout << "Dragon Claw" << std::setw(20) << "Damage:" << std::setw(5) 
		<< -60 << std::setw(21) << "Hit Probability:" << std::setw(5) << 65 << std::endl;
	std::cout << "Ember" << std::setw(26) << "Damage:" << std::setw(5) 
		<< -40 << std::setw(21) << "Hit Probability:" << std::setw(5) << 90 << std::endl;
	std::cout << "Headbutt" << std::setw(23) << "Damage:" << std::setw(5) 
		<< -30 << std::setw(21) << "Hit Probability:" << std::setw(5) << 90 << std::endl;
	std::cout << "Flare Blitz" << std::setw(20) << "Damage:" << std::setw(5)
		<< -75 << std::setw(21) << "Hit Probability:" << std::setw(5) << 55 << std::endl;
}

//Squirtle's information
void PokemonID::squirtle() const {
	std::cout << "==============================================================" << std::endl;
	std::cout << std::setw(42) << "Pokemon Information" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Name: Squirtle" << std::setw(22) << "Num: #007" << std::setw(26) << "Type: Water" << std::endl;
	std::cout << "Gender: Female" << std::setw(22) << "Height: 0.5 m" << std::setw(26) << "Weight: 9 kg" << std::endl;
	std::cout << std::endl << std::setw(35) << "Moves" << std::endl;
	std::cout << "Ice Punch" << std::setw(22) << "Damage:" << std::setw(5)
		<< -55 << std::setw(21) << "Hit Probability:" << std::setw(5) << 75 << std::endl;
	std::cout << "Skull Bash" << std::setw(21) << "Damage:" << std::setw(5)
		<< -35 << std::setw(21) << "Hit Probability:" << std::setw(5) << 90 << std::endl;
	std::cout << "Water Gun" << std::setw(22) << "Damage:" << std::setw(5)
		<< -40 << std::setw(21) << "Hit Probability:" << std::setw(5) << 100 << std::endl;
	std::cout << "Aqua Jet" << std::setw(23) << "Damage:" << std::setw(5)
		<< -80 << std::setw(21) << "Hit Probability:" << std::setw(5) << 50 << std::endl;
}

//Pikachu's(Bot's) information
void PokemonID::pikachu() const {
	std::cout << "==============================================================" << std::endl;
	std::cout << std::setw(42) << "Pokemon Information" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "Name: Pikachu" << std::setw(23) << "Num: #025" << std::setw(26) << "Type: Electric" << std::endl;
	std::cout << "Gender: Female" << std::setw(22) << "Height: 0.4 m" << std::setw(26) << "Weight: 6 kg" << std::endl;
	std::cout << std::endl << std::setw(35) << "Moves" << std::endl;
	std::cout << "Thunder" << std::setw(24) << "Damage:" << std::setw(5) 
		<< -90 << std::setw(21) << "Hit Probability:" << std::setw(5) << 55 << std::endl;
	std::cout << "Thunderbolt" << std::setw(20) << "Damage:" << std::setw(5) 
		<< -50 << std::setw(21) << "Hit Probability:" << std::setw(5) << 90 << std::endl;
	std::cout << "Quick Attack" << std::setw(19) << "Damage:" << std::setw(5) 
		<< -25 << std::setw(21) << "Hit Probability:" << std::setw(5) << 100 << std::endl;
	std::cout << "Rest" << std::setw(27) << "Damage:" << std::setw(5) 
		<< +60 << std::setw(21) << "Hit Probability:" << std::setw(5) << 65 << std::endl;
}