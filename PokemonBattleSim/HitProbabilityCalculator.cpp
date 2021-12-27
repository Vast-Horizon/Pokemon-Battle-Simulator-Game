#include "HitProbabilityCalculator.h"

HitProbabilityCalculator::HitProbabilityCalculator(bool h, int pv) {
	probabilityValue = pv;
	hitVerify = false;
	hitOutcomes(pv);
}

void HitProbabilityCalculator::hitOutcomes(int pv) {
	int randomNum, min = 0, max = 100;

	randomNum = min + (rand() % (max - min + 1));

	//Ex: A number between 0 and 100 will be generated. 
	//For 25% you must get any number equal or lower than 
	//25 to score a hit otherwise there will be a miss. 
	
	if (randomNum <= pv)
		setHitVerify(true);
	else
		setHitVerify(false);
}