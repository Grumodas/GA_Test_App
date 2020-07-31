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
	pop.PrintInfo();

	while (pop.fittest.fitness < pop.fittest.geneLength) {
		pop.Selection();
		pop.Crossover();
		pop.Mutation(7);
		pop.AddFittestOffspring();
		pop.RecalculateFitness();
		pop.IncGen();
		pop.PrintInfo();
	}

	return 0;
}
