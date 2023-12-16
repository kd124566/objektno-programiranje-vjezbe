#include "Food.h"
#include <iostream>
#include <string>

int Food::counter = 0;

Food::Food()
{
	counter = 1;
}

int Food::brojac()
{
	return counter;
}
void Food::povecaj()
{
	counter += 1;
}
void Food::smanji()
{
	counter -= 1;
}
void Food::isprintaj()
{
	std::cout << "Counter je: " << counter << "\n";
}
int get_counter()
{
	return Food::brojac();
}