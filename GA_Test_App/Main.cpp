#include <ctime>
#include <iostream>
#include "Population.h"

using namespace std;

int main() {
	//settings up the seed for rand() (works globally)
	srand((unsigned) time(0));

	int populationSize = 5;
	Population pop(populationSize);
	pop.Print();
	pop.GetFittest().PrintGenes();
	pop.GetSecondFittest().PrintGenes();
	pop.individuals.at(pop.GetLeastFittestIndex()).PrintGenes();
	return 0;
}
