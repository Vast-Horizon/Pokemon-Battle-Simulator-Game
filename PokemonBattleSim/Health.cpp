#include "Health.h"

//calculate the health point (HP) then returns it
double Health::healthCalculator(double hp, double damage) {
	hp += damage;
	return hp;
}