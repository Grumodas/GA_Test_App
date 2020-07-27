#include "Individual.h"
#include <vector>
#include <string>

class Population {
public:
	int populationSize = 0, generationCount = 0;
	vector<Individual> individuals;
	Individual fittest, secondFittest;

	Population(int populationSize) {
		this->populationSize = populationSize;

		for (int i = 0; i < populationSize; i++) {
			Individual ind;
			individuals.push_back(ind);
		}
	}

	void Print();
	Individual GetFittest();
	Individual GetSecondFittest();
	int GetLeastFittestIndex();
	void RecalculateFitness();

	void Selection();
	void Crossover();
	void Mutation();
	Individual GetFittestOffspring();
	void AddFittestOffspring();

};