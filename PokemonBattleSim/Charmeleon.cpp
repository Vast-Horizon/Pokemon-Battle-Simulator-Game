/*
The second Pokemon ---- Charmeleon
For more detailed information, please check the project report
*/
#include "Charmeleon.h"
#include <iomanip>
double Charmeleon::attack() {
		
	int option;
	option = dodge();

	double temp = 0.0;

	switch (option) {
		case 1:
			if (dr.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << dr.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {//use the move
				std::cout << std::endl;
				std::cout << NAME << " used " << dr.name << "." << std::endl;
				dr.limit--;
				temp = dr.damage;
				std::cin.get();
				break;
			}
		case 2:
			if (em.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << em.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << em.name << "." << std::endl;;
				em.limit--;
				temp = em.damage;
				std::cin.get();
				break;
			}
		case 3:
			if (he.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << he.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << he.name << "." << std::endl;;
				he.limit--;
				temp = he.damage;
				std::cin.get();
				break;

			}
		case 4:
			if (fl.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << fl.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << fl.name << "." << std::endl;;
				fl.limit--;
				temp = fl.damage;
				std::cin.get();
				break;
			}
		case 0://in case the opposing bot dodge a move, check which move is it, then send a message to the player
			if (opt == 1) {
				if (dr.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << dr.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << dr.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				dr.limit--;
				std::cin.get();
			}
			else if (opt == 2) {
				if (em.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << em.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << em.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				em.limit--;
				std::cin.get();
			}
			else if (opt == 3) {
				if (he.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << em.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << he.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				he.limit--;
				std::cin.get();
			}
			else if (opt == 4) {
				if (fl.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << fl.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << fl.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				fl.limit--;
				std::cin.get();
			}
	}

	return temp;
}

int Charmeleon::dodge() {

	int move;

	do {
		std::cout << "Please choose a move: ";
		std::cin >> move;

		opt = move;
		setOPT(move);

		//use hitOutcomes to determine dodge
		//hitOutcomes returns a boolean value
		if (move == 1)
			hitOutcomes(dr.probability);
		else if (move == 2)
			hitOutcomes(em.probability);
		else if (move == 3)
			hitOutcomes(he.probability);
		else if (move == 4)
			hitOutcomes(fl.probability);
		else {
			std::cout << "Choose a move (1-4)" << std::endl;
		}
	} while (move < 1 || move > 4);


	if (getHitVerify() == true) {
		return opt;
	}
	else
		return 0;
}


//activates the attack function
std::istream& operator >> (std::istream& in, Charmeleon& n) {
	n.botDamage = n.attack();
	return in;
}
//outputs remaining limits
std::ostream& operator << (std::ostream& out, Charmeleon& n) {
	out << "1. " << n.dr.name << std::setw(5) << n.dr.limit << "/5" << std::endl;
	out << "2. " << n.em.name << std::setw(10) << n.em.limit << "/10" << std::endl;
	out << "3. " << n.he.name << std::setw(7) << n.he.limit << "/10" << std::endl;
	out << "4. " << n.fl.name << std::setw(5) << n.fl.limit << "/5" << std::endl;
	return out;
}
