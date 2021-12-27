/****************************************************************
Project Name: Pokemon Battle Simulator

Developers:
Fiavi Yang, Pierce Kam, Adam Khalid, Sumreen Aamir

Instructor: Nasim Muhammad
Department and Institution: Engineering, McMaster University

Date of Submission: April 4, 2021
*******************************************************************/


//include Pokemon classes header files
#include "Pikachu.h"
#include "Torterra.h"
#include "Charmeleon.h"
#include "Squirtle.h"

//aggregated PokemonID class
#include "PokemonID.h"

//include file operation header file
#include <fstream>
//include windows API header file
#include <windows.h>

using namespace std;

int main() {
	//Message Box
	MessageBoxW(NULL, L"Pokemon Battle Simulator",L"Pokemon Battle Simulator", MB_ICONASTERISK | MB_OK); 

	PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); // play bgm

	
	//initialize input variables
	int pok = 1;
	int id = 0;
	//create ID object
	PokemonID info;

	// Welcome and information menu
	cout << "========================================================" << endl;
	cout << setw(47) << "Welcome to the Pokemon Battle Simulator" << endl;
	cout << "========================================================" << endl;
	cout << "1. Torterra" << endl;
	cout << "2. Charmeleon" << endl;
	cout << "3. Squirtle" << endl;
	cout << "4. Pikachu" << endl;
	
	do {
		cout << "========================================================" << endl;
		cout << "Please choose a Pokemon to learn more information about." << endl;
		cout << "Enter 0 to skip." << endl;
		cout << "========================================================" << endl;
		cout << "Your choice: ";
		cin >> id;
		if (id > 4 || id < 0) {//input validation
			std::cout << "Please enter a value (1-4)." << std::endl;
		}
		info.getID(id);
	} while (id != 0);

	//Selection menu
	do {
		cout << endl;
		cout << "========================================================" << endl;
		cout << setw(37) << "Select a Pokemon" << endl;
		cout << "========================================================" << endl;
		cout << "1. Torterra" << endl;
		cout << "2. Charmeleon" << endl;
		cout << "3. Squirtle" << endl;
		cout << "========================================================" << endl;
		cout << "Your choice: ";
		cin >> pok;

		if (pok != 1 && pok != 2 && pok != 3)//input validation
			cout << "Please select 1, or 2, or 3." << endl;
	} while (pok != 1 && pok != 2 && pok != 3);
	

	//from 1 to 3, one case for one Pokemon
	switch (pok) {
		case 1: {
			//create Pokemon objects
			Torterra player;
			Pikachu *bot = new Pikachu;

			bool keepGoing = true;//initialize and set the looping condition to true
			double hit, bot_hit; // store the damage from player's Pokemon and the bot
			int counter = 1; //round counter

			while (keepGoing) { 
				// Round Display
				cout << endl << endl;
				cout << "========================================================" << endl;
				cout << setw(30) << "Round " << counter << endl;
				cout << "========================================================";
				
				// Game Interface
				cout << endl << "===================" << setw(37) << "==================" << endl;
				cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
				cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
				cout << "===================" << setw(37) << "==================" << endl;
				
				cout << player;//using output overloaded operator to display limits
				cin >> player;//using input overloaded operator to activate the member function in the object
				cout << endl;

				hit = player.getBotD(); //takes the damage from the player Pokemon
				bot->setPlayerD(hit); // the bot loses that much health point(HP)

				bot_hit = bot->attack(); //takes the damage from the bot Pokemon
				player.setHP(bot_hit); // the player Pokemon loses that much health point(HP)

				//Game over detection
				if (bot->getBotHP() < 0 || player.getHP() < 0) { //game is over when the HP from one side belows 0
					//if the bot Pokemon's HP <0, the winner is the player Pokemon
					if (bot->getBotHP() < 0) {
						cout << "The winner is " << player.getNAME() << endl;//display who won the game

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << 0 << "  |" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Torterra", L"Congratulation", MB_ICONASTERISK | MB_OK);

					}
					//if the player Pokemon's HP < 0, the winner is the bot
					else {
						cout << "The winner is " << bot->getNAME() << endl;

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << 0 << "  |";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Pikachu", L"Try again", MB_ICONASTERISK | MB_OK);
						
					}
					
					
				
					//open(create) a txt file, stores the winner information to that file
					ofstream winnerFile;
					winnerFile.open("WinnerLog.txt", ios::app);
					if (bot->getBotHP() < 25) {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is " << player.getNAME() << endl;
						winnerFile << "Health: " << player.getHP() << endl;
						winnerFile << player << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << bot->getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl << endl;
					}
					else {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is Pikachu" << endl;
						winnerFile << "Health: " << bot->getBotHP() << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << player.getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl << endl;
					}
					winnerFile.close();

					cout << player;
					keepGoing = false; //Ends the game
					break;
				}

				counter++;//round counter + 1
			}

			break;
		}

		case 2: {
			Charmeleon player;
			Pikachu* bot = new Pikachu;

			bool keepGoing = true;
			double hit, bot_hit;
			int counter = 1;

			while (keepGoing) {
				// Round Display
				cout << endl << endl;
				cout << "========================================================" << endl;
				cout << setw(30) << "Round " << counter << endl;
				cout << "========================================================";

				// Game Interface
				cout << endl << "===================" << setw(37) << "==================" << endl;
				cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
				cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
				cout << "===================" << setw(37) << "==================" << endl;

				cout << player;
				cin >> player;
				cout << endl;
				hit = player.getBotD(); //takes the damage to the bot
				bot->setPlayerD(hit); // the bot loses that much hp

				bot_hit = bot->attack();
				player.setHP(bot_hit);

				//Game over detection
				if (bot->getBotHP() < 0 || player.getHP() < 0) {
					if (bot->getBotHP() < 0) {
						cout << "The winner is " << player.getNAME() << endl;

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << 0 << "  |" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Charmeleon", L"Congratulation", MB_ICONASTERISK | MB_OK);
					}
					else {
						cout << "The winner is " << bot->getNAME() << endl;

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << 0 << "  |";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Pikachu", L"Try again", MB_ICONASTERISK | MB_OK);

					}



					//open(create) a txt file, stores the winner information to that file
					ofstream winnerFile;
					winnerFile.open("WinnerLog.txt", ios::app);
					if (bot->getBotHP() < 25) {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is " << player.getNAME() << endl;
						winnerFile << "Health: " << player.getHP() << endl;
						winnerFile << player << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << bot->getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl << endl;
					}
					else {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is Pikachu" << endl;
						winnerFile << "Health: " << bot->getBotHP() << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << player.getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl << endl;
					}
					winnerFile.close();

					cout << player;
					keepGoing = false; //Ends the game
					break;
				}

				counter++;
			}

			break;
		}

		case 3: {
			Squirtle player;
			Pikachu* bot = new Pikachu;

			bool keepGoing = true;
			double hit, bot_hit;
			int counter = 1;

			while (keepGoing) {
				// Round Display
				cout << endl << endl;
				cout << "========================================================" << endl;
				cout << setw(30) << "Round " << counter << endl;
				cout << "========================================================";

				// Game Interface
				cout << endl << "===================" << setw(37) << "==================" << endl;
				cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
				cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
				cout << "===================" << setw(37) << "==================" << endl;

				cout << player;
				cin >> player;
				cout << endl;
				hit = player.getBotD(); //takes the damage to the bot
				bot->setPlayerD(hit); // the bot loses that much hp

				bot_hit = bot->attack();
				player.setHP(bot_hit);

				//Game over detection
				if (bot->getBotHP() < 0 || player.getHP() < 0) {
					if (bot->getBotHP() < 0) {
						cout << "The winner is " << player.getNAME() << endl;

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << player.getHP() << "|";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << 0 << "  |" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Squirtle", L"Congratulation", MB_ICONASTERISK | MB_OK);
					}
					else {
						cout << "The winner is " << bot->getNAME() << endl;

						cout << endl << "===================" << setw(37) << "==================" << endl;
						cout << "|" << player.getNAME() << "  HP: " << 0 << "  |";
						cout << setw(20) << "|" << bot->getNAME() << "  HP: " << bot->getBotHP() << "|" << endl;
						cout << "===================" << setw(37) << "==================" << endl;
						MessageBoxW(NULL, L"The winner is Pikachu", L"Try again", MB_ICONASTERISK | MB_OK);

					}



					//open(create) a txt file, stores the winner information to that file
					ofstream winnerFile;
					winnerFile.open("WinnerLog.txt", ios::app);
					if (bot->getBotHP() < 25) {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is " << player.getNAME() << endl;
						winnerFile << "Health: " << player.getHP() << endl;
						winnerFile << player << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << bot->getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl << endl;
					}
					else {
						winnerFile << "Displaying the Winner's Information" << endl;
						winnerFile << "===================================" << endl;
						winnerFile << "The Winner is Pikachu" << endl;
						winnerFile << "Health: " << bot->getBotHP() << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << "Opponent Information" << endl;
						winnerFile << "-----------------------------------" << endl;
						winnerFile << player.getNAME() << setw(25) << "Health: " << 0 << endl;
						winnerFile << endl<< endl;
					}
					winnerFile.close();

					cout << player;
					keepGoing = false; //Ends the game
					break;
				}

				counter++;
			}

			break;
		}

		default:
			MessageBoxW(NULL, L"UNEXPECTED ERROR", L"Please restart the game", MB_ICONHAND | MB_OK);  // UNEXPECTED ERROR
		
	}

	return 0;
}