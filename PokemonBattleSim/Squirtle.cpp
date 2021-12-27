/*
The third Pokemon ---- Squirtle
For more detailed information, please check the project report
*/
#include "Squirtle.h"

double Squirtle::attack() {

	int option;
	option = dodge();

	double temp = 0.0;

	switch (option) {
	case 1:
		if (ic.limit < 1) {//limit check
			std::cout << std::endl;
			std::cout << ic.name << " can't be used anymore." << std::endl;
			std::cin.get();
			break;
		}
		else {//do the move
			std::cout << std::endl;
			std::cout << NAME << " used " << ic.name << "." << std::endl;
			ic.limit--;
			temp = ic.damage;
			std::cin.get();
			break;
		}
	case 2:
		if (sk.limit < 1) {//limit check
			std::cout << std::endl;
			std::cout << sk.name << " can't be used anymore." << std::endl;
			std::cin.get();
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << NAME << " used " << sk.name << "." << std::endl;;
			sk.limit--;
			temp = sk.damage;
			std::cin.get();
			break;
		}
	case 3:
		if (wa.limit < 1) {//limit check
			std::cout << std::endl;
			std::cout << wa.name << " can't be used anymore." << std::endl;
			std::cin.get();
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << NAME << " used " << wa.name << "." << std::endl;
			wa.limit--;
			temp = wa.damage;
			std::cin.get();
			break;
		}
	case 4:
		if (aq.limit < 1) {//limit check
			std::cout << std::endl;
			std::cout << aq.name << " can't be used anymore." << std::endl;
			std::cin.get();
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << NAME << " used " << aq.name << "." << std::endl;;
			aq.limit--;
			temp = aq.damage;
			std::cin.get();
			break;
		}
	case 0:
		if (opt == 1) {//in case the opposing bot dodge a move, check which move is it, then send a message to the player
			if (ic.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << ic.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			std::cout << std::endl;
			std::cout << NAME << " used " << ic.name << "." << std::endl;
			std::cout << "The opposing Pikachu dodged the attack!";
			ic.limit--;
			std::cin.get();
		}
		else if (opt == 2) {
			if (sk.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << sk.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			std::cout << std::endl;
			std::cout << NAME << " used " << sk.name << "." << std::endl;
			std::cout << "The opposing Pikachu dodged the attack!";
			sk.limit--;
			std::cin.get();
		}
		else if (opt == 3) {
			if (wa.limit < 1) {//limit check
				std::cout << std::endl;
				std::cout << wa.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			std::cout << std::endl;
			std::cout << NAME << " used " << wa.name << "." << std::endl;
			std::cout << "The opposing Pikachu dodged the attack!";
			wa.limit--;
			std::cin.get();
		}
		else if (opt == 4) {
			if (aq.limit <= 1) {//limit check
				std::cout << std::endl;
				std::cout << aq.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			std::cout << std::endl;
			std::cout << NAME << " used " << aq.name << "." << std::endl;
			std::cout << "The opposing Pikachu dodged the attack!";
			aq.limit--;
			std::cin.get();
		}
	}

	return temp;
}

int Squirtle::dodge() {
	int move;

	do {
		std::cout << "Please choose a move: ";
		std::cin >> move;

		opt = move;
		setOPT(move);

		//use hitOutcomes to determine dodge
		//hitOutcomes returns a boolean value
		if (move == 1)
			hitOutcomes(ic.probability);
		else if (move == 2)
			hitOutcomes(sk.probability);
		else if (move == 3)
			hitOutcomes(wa.probability);
		else if (move == 4)
			hitOutcomes(aq.probability);
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
std::istream& operator >> (std::istream& in, Squirtle& n) {
	n.botDamage = n.attack();
	return in;
}

//outputs remaining limits
std::ostream& operator << (std::ostream& out, Squirtle& n) {
	out << "1. " << n.ic.name << std::setw(7) << n.ic.limit << "/5" << std::endl;
	out << "2. " << n.sk.name << std::setw(5) << n.sk.limit << "/10" << std::endl;
	out << "3. " << n.wa.name << std::setw(6) << n.wa.limit << "/10" << std::endl;
	out << "4. " << n.aq.name << std::setw(8) << n.aq.limit << "/5" << std::endl;
	return out;
}
