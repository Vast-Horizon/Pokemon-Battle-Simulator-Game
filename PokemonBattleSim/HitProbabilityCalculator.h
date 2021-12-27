#ifndef HITPROBABILITYCALCULATOR_H
#define HITPROBABILITYCALCULATOR_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

class HitProbabilityCalculator {
	protected:
		bool hitVerify;//stores the hit verification result
		int probabilityValue;//stores the probability value

	public:
		HitProbabilityCalculator() { hitVerify = false; probabilityValue = 0; }
		HitProbabilityCalculator(bool, int);

		// mutator functions
		void setHitVerify(bool hv) { hitVerify = hv; }
		void setProbabilityValue(int pv) { probabilityValue = pv; }

		// accessor functions
		bool getHitVerify() const { return hitVerify; }
		int getProbabilityValue() const { return probabilityValue; }

		// member functions
		void hitOutcomes(int);

		// destructor
		~HitProbabilityCalculator() {}
};
#endif