/*
The fourth Pokemon(The bot) ---- Pikachu
For more information, please check the project report
*/
#ifndef PIKACHU_H
#define PIKACHU_H
#include "Health.h"
#include "HitProbabilityCalculator.h"

class Pikachu : public Health, public HitProbabilityCalculator {//inherited from Health and  HitProbabilityCalculator
	protected:
		double pikaHealth = healthAry[0];//get the health point
		int opt = 0;
		std::string NAME = "Pikachu";
		int m;

		//Move structures
		struct Thunder {
			std::string name = "Thunder";
			double damage = -90;
			int probability = 55;
			int limit = 5;
		};
		Thunder t;

		struct Thunderbolt {
			std::string name = "Thunderbolt";
			double damage = -50;
			int probability = 90;
			int limit = 10;
		};
		Thunderbolt tb;

		struct QuickAttack {
			std::string name = "Quick Attack";
			double damage = -25;
			int probability = 100;
			int limit = 10;
		};
		QuickAttack qa;

		struct Rest {
			std::string name = "Rest";
			double damage = 45;
			int probability = 50;
			int limit = 5;
		};
		Rest r;

	public:
		Pikachu() { opt = 1; NAME = "Pikachu"; }

		void setPlayerD(double d) { pikaHealth = healthCalculator(pikaHealth, d); }
		void setBotHP(double h) { pikaHealth = h; }
		void setNAME(std::string n) { NAME = n; }

		std::string getNAME() const { return NAME; }
		double getBotHP()const { return pikaHealth; }
		double getBotProb()const { return t.probability; }

		virtual double attack();
		int randomizer();
};
#endif;