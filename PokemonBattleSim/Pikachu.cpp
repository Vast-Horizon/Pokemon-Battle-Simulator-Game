/*
The fourth Pokemon(The bot) ---- Pikachu
For more detailed information, please check the project report
*/
#include "Pikachu.h"

double Pikachu::attack() {

	int randNum = randomizer();////activates the randomizer() and get its results

	double temp = 0.0;

	switch (randNum) {
		case 1:
			//limit check
			if (t.limit <= 1) {
				std::cout << std::endl;
				std::cout << NAME << "'s " << t.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			//do the move
			else {
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << t.name << "." << std::endl;
				t.limit--;//deduct the limit by 1
				temp = t.damage;
				std::cin.get();//pause
				break;
			}
		case 2:
			if (tb.limit <= 1) {
				std::cout << std::endl;
				std::cout << NAME << "'s " << tb.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << tb.name << "." << std::endl;
				tb.limit--;
				temp = tb.damage;
				std::cin.get();
				break;
			}
		case 3:
			if (qa.limit <= 1) {
				std::cout << std::endl;
				std::cout << NAME << "'s " << qa.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << qa.name << "." << std::endl;
				qa.limit--;
				temp = qa.damage;
				std::cin.get();
				break;
			}
		case 4:
			if (r.limit <= 1) {
				std::cout << std::endl;
				std::cout << NAME << "'s " << r.name << " can't be used anymore." << std::endl;
				std::cin.get();
				break;
			}
			else {
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << r.name << "." << std::endl;
				r.limit--;

				double h = pikaHealth + r.damage;
				if (h > 283) {
					pikaHealth = 283;
					std::cout << "The opposing Pikachu was fully healed." << std::endl;
					std::cin.get();
				}
				else {
					pikaHealth += r.damage;
					std::cout << "The opposing Pikachu was healed." << std::endl;
					std::cin.get();
				}
				break;
			}
		case 0:
			if (m == 1) {
				if (t.limit <= 1) {
					std::cout << std::endl;
					std::cout << NAME << "'s " << t.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << t.name << "." << std::endl;
				std::cout << "Your Pokemon dodged the attack!" << std::endl;
				t.limit--;
				std::cin.get();
			}
			else if (m == 2) {
				if (tb.limit <= 1) {
					std::cout << std::endl;
					std::cout << NAME << "'s " << tb.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << tb.name << "." << std::endl;
				std::cout << "Your Pokemon dodged the attack!" << std::endl;
				tb.limit--;
				std::cin.get();
			}
			else if (m == 3) {
				if (qa.limit <= 1) {
					std::cout << std::endl;
					std::cout << NAME << "'s " << qa.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << qa.name << "." << std::endl;
				std::cout << "Your Pokemon dodged the attack!" << std::endl;
				qa.limit--;
				std::cin.get();
			}
			else if (m == 4) {
				if (r.limit <= 1) {
					std::cout << std::endl;
					std::cout << NAME << "'s " << r.name << " can't be used anymore." << std::endl;
					std::cin.get();
					break;
				}
				std::cout << std::endl;
				std::cout << "The opposing Pikachu used " << r.name << "." << std::endl;
				std::cout << "But it failed." << std::endl;
				r.limit--;
				std::cin.get();
			}
	}

	return temp;
}

//the randomizer() function acts like the dodge() function in the other Pokemon
//but instead asking player's option, it use random number to determine the move
int Pikachu::randomizer() {
	int move;

	srand((unsigned)time(0));

	const int MIN = 1, MAX = 4;

	move = MIN + (rand() % (MAX - MIN + 1));
	m = move;

	if (move == 1)
		hitOutcomes(t.probability);
	else if (move == 2)
		hitOutcomes(tb.probability);
	else if (move == 3)
		hitOutcomes(qa.probability);
	else
		hitOutcomes(r.probability);

	if (getHitVerify() == true) {
		return move;
	}
	else
		return 0;
}