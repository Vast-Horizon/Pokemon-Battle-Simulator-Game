/*
The first Pokemon ---- Torterra
For more information, please check the project report
*/

#include "Torterra.h"

double Torterra::attack() {

	int option;
	option = dodge();//activates the dodge and get its results

	double temp = 0.0;//create a temporary value for damage return

	switch (option) {
		case 1:
			//limit check
			if (rl.limit < 1) {
				std::cout << std::endl;
				std::cout << rl.name << " can't be used anymore." << std::endl;//cannot use this move anymore
				std::cin.get();//pause
				break;
			}
			//do the move
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << rl.name << "." << std::endl;
				rl.limit--;//deduct the limit by 1
				temp = rl.damage;
				std::cin.get();//pause
				break;
			}
		case 2:
			if (eq.limit < 1) {
				std::cout << std::endl;
				std::cout << eq.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << eq.name << "." << std::endl;;
				eq.limit--;
				temp = eq.damage;
				std::cin.get();
				break;
			}
		case 3:
			//Synthesis is a heal move, which means it increases health point of Torerra
			if (ss.limit < 1) {
				std::cout << std::endl;
				std::cout << ss.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << ss.name << "." << std::endl;
				ss.limit--;

				double h = tortHealth + ss.damage;//increase the health point
				if (h > 321) {
					tortHealth = 321;
					std::cout << NAME << " was fully healed." << std::endl;
					std::cin.get();
				}
				else {
					tortHealth += ss.damage;
					std::cout << NAME << " was healed." << std::endl;
					std::cin.get();
				}
				break;
			}
		case 4:
			if (wh.limit < 1) {
				std::cout << std::endl;
				std::cout << wh.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << NAME << " used " << wh.name << "." << std::endl;;
				wh.limit--;
				temp = wh.damage;
				std::cin.get();
				break;
			}
		case 0: //in case the opposing bot dodge a move, check which move is it, then send a message to the player
			if (opt == 1) {
				if (rl.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << rl.name << " can't be used anymore." << std::endl;//cannot use this move anymore
					std::cin.get();//pause
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << rl.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				rl.limit--;
				std::cin.get();//pause
			}
			else if (opt == 2) {
				if (eq.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << eq.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << eq.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				eq.limit--;
				std::cin.get();
			}
			else if (opt == 3) {
				if (ss.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << ss.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << ss.name << "." << std::endl;
				std::cout << "But it failed.";
				ss.limit--;
				std::cin.get();
			}
			else if (opt == 4) {
				if (wh.limit < 1) {//limit check
					std::cout << std::endl;
					std::cout << wh.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << NAME << " used " << wh.name << "." << std::endl;
				std::cout << "The opposing Pikachu dodged the attack!";
				wh.limit--;
				std::cin.get();
			}
	}

	return temp;
}

int Torterra::dodge() {
	int move;

	do {
		std::cout << "Please choose a move: ";
		std::cin >> move;

		opt = move;
		setOPT(move);

		//use hitOutcomes to determine dodge
		//hitOutcomes returns a boolean value
		if (move == 1)
			hitOutcomes(rl.probability);
		else if (move == 2)
			hitOutcomes(eq.probability);
		else if (move == 3)
			hitOutcomes(ss.probability);
		else if (move == 4)
			hitOutcomes(wh.probability);
		else {
			std::cout << "Choose a move (1-4)" << std::endl;
		}
	} while (move < 1 || move > 4);//input validation


	if (getHitVerify() == true) {
		return opt;
	}
	else
		return 0;
}

//activates the attack function
std::istream& operator >> (std::istream& in, Torterra& n) {
	n.botDamage = n.attack();
	return in;
}

//outputs remaining limits
std::ostream& operator << (std::ostream& out, Torterra& n) {
	out << "1. " << n.rl.name << std::setw(5) << n.rl.limit << "/10" << std::endl;
	out << "2. " << n.eq.name << std::setw(6) << n.eq.limit << "/5" << std::endl;
	out << "3. " << n.ss.name << std::setw(6) << n.ss.limit << "/10" << std::endl;
	out << "4. " << n.wh.name << std::setw(5) << n.wh.limit << "/5" << std::endl;
	return out;
}
