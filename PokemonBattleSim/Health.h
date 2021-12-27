#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>

class Health {
	protected:
		double healthAry[4] = { 283,321,307,275 }; // stores initial health point(hp) for every Pokemon
	public:

		double healthCalculator(double, double);//calculate the health point (HP) then returns it
		virtual double attack() = 0;//pure virtual function
};
#endif

