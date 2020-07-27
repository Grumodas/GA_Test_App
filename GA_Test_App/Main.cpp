#include <ctime>
#include <iostream>
#include "Population.h"

using namespace std;

int main() {
	//settings up the seed for rand() (works globally)
	srand((unsigned) time(0));

	int populationSize = 10;
	Population pop(populationSize);
	pop.Print();
	pop.GetFittest().PrintGenes();
	pop.GetSecondFittest().PrintGenes();
	pop.Selection();
	pop.Crossover();
	pop.fittest.PrintGenes();
	pop.secondFittest.PrintGenes();
	return 0;
}
