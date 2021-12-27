/*
The second Pokemon ---- Charmeleon
For more information, please check the project report
*/
#ifndef CHARMELEON_H
#define CHARMELEON_H
#include "Health.h"
#include "Pikachu.h"
#include "HitProbabilityCalculator.h"

class Charmeleon : public Health, public HitProbabilityCalculator {
	protected:
		double charHealth = healthAry[2];//initialize the health point from the health class
		int opt;
		double botDamage = 0;
		std::string NAME = "Charmeleon";

		//Move structures
		struct DragonClaw {
			std::string name = "Dragon Claw";
			double damage = -60;
			int probability = 65;
			int limit = 5;
		};
		DragonClaw dr;

		struct Ember {
			std::string name = "Ember";
			double damage = -40;
			int probability = 90;
			int limit = 10;
		};
		Ember em;

		struct Headbutt {
			std::string name = "Headbutt";
			double damage = -30;
			int probability = 90;
			int limit = 10;
		};
		Headbutt he;

		struct FlareBlitz {
			std::string name = "Flare Blitz";
			double damage = -75;
			int probability = 55;
			int limit = 5;
		};
		FlareBlitz fl;

	public:

		Charmeleon() { botDamage = 0; NAME = "Charmeleon"; }

	
		void setHP(double d) { charHealth = healthCalculator(charHealth, d); }
		void setBotD(double bd) { botDamage = bd; }
		void setNAME(std::string n) { NAME = n; }
		void setOPT(int o) { opt = o; }

		double getHP()const { return charHealth; }
		double getBotD()const { return botDamage; }
		std::string getNAME() const { return NAME; }
		int getOPT() const { return opt; }

		virtual double attack();
		virtual int dodge();

		friend std::istream& operator >> (std::istream&, Charmeleon&);
		friend std::ostream& operator << (std::ostream&, Charmeleon&);

		~Charmeleon() {}
};
#endif