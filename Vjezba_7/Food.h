#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <iostream>

class Food {
private:

	static int counter;
public:

	Food();

	static int brojac();
	static void povecaj();
	static void smanji();
	static void isprintaj();

};

int get_counter();

#endif