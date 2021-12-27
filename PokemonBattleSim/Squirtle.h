/*
The third Pokemon ---- Squirtle
For more detailed information, please check the project report
*/

#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include "Health.h"
#include "Pikachu.h"
#include "HitProbabilityCalculator.h"

#include <iomanip>

class Squirtle : public Health, public HitProbabilityCalculator {//inherited from Health and  HitProbabilityCalculator
	protected:
		double squirHealth = healthAry[3];
		int opt;
		double botDamage = 0;
		std::string NAME = "Squirtle";

		struct IcePunch {
			std::string name = "Ice Punch";
			double damage = -55;
			int probability = 75;
			int limit = 5;
		};
		IcePunch ic;

		struct SkullBash {
			std::string name = "Skull Bash";
			double damage = -35;
			int probability = 90;
			int limit = 10;
		};
		SkullBash sk;

		struct WaterGun {
			std::string name = "Water Gun";
			double damage = -40;
			int probability = 85;
			int limit = 10;
		};
		WaterGun wa;

		struct AquaJet {
			std::string name = "Aqua Jet";
			double damage = -80;
			int probability = 50;
			int limit = 5;
		};
		AquaJet aq;


	public:

		Squirtle() { botDamage = 0; NAME = "Squirtle"; }


		void setHP(double d) { squirHealth = healthCalculator(squirHealth, d); }
		void setBotD(double bd) { botDamage = bd; }
		void setNAME(std::string n) { NAME = n; }
		void setOPT(int o) { opt = o; }

		double getHP()const { return squirHealth; }
		double getBotD()const { return botDamage; }
		std::string getNAME() const { return NAME; }
		int getOPT() const { return opt; }

		virtual double attack();
		virtual int dodge();

		friend std::istream& operator >> (std::istream&, Squirtle&);
		friend std::ostream& operator << (std::ostream&, Squirtle&);

		~Squirtle() {}
};
#endif