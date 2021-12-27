/*
The first Pokemon ---- Torterra
For more information, please check the project report
*/

#ifndef TORTERRA_H
#define TORTERRA_H
#include "Health.h"
#include "Pikachu.h"
#include "HitProbabilityCalculator.h"

#include <iomanip>

class Torterra : public Health, public HitProbabilityCalculator {//inherited from Health and  HitProbabilityCalculator
	protected:
		double tortHealth = healthAry[1];// get the initial health point from Health class
		int opt;// stores input option
		double botDamage = 0; // stores damage of the move
		std::string NAME = "Torterra"; //name of this Pokemon

		//Move structures
		struct RazorLeaf {
			std::string name = "Razor Leaf";
			double damage = -25;
			int probability = 90;
			int limit = 10;
		};
		RazorLeaf rl;

		struct Earthquake {
			std::string name = "Earthquake";
			double damage = -70;
			int probability = 40;
			int limit = 5;
		};
		Earthquake eq;

		struct Synthesis {//Synthesis is a heal move, which means it increases health point of Torerra
			std::string name = "Synthesis";
			double damage = 35;
			int probability = 60;
			int limit = 10;
		};
		Synthesis ss;

		struct WoodHammer {
			std::string name = "Wood Hammer";
			double damage = -80;
			int probability = 50;
			int limit = 5;
		};
		WoodHammer wh;

	public:
		//default constructor
		Torterra() { botDamage = 0; NAME = "Torterra"; }

		//mutators
		void setHP(double d) { tortHealth = healthCalculator(tortHealth, d); }
		void setBotD(double bd) { botDamage = bd; }
		void setNAME(std::string n) { NAME = n; }
		void setOPT(int o) { opt = o; }

		//accessors
		double getHP() const { return tortHealth; }
		double getBotD() const { return botDamage; }
		std::string getNAME() const { return NAME; }
		int getOPT() const { return opt; }

		virtual double attack();
		virtual int dodge();

		friend std::istream& operator >> (std::istream&, Torterra&);
		friend std::ostream& operator << (std::ostream&, Torterra&);

		//default destructor
		~Torterra() {}
};
#endif