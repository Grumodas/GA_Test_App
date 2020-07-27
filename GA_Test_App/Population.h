#include "Individual.h"
#include <vector>
#include <string>

class Population {
public:
	int populationSize;
	vector<Individual> individuals;
	int fittest = 0;

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
};