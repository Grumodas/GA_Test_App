#include "Population.h"
using namespace std;

void Population::Print() {
	cout << "Printing population: ";
	for (int i = 0; i < this->populationSize; i++) {
		for (int j = 0; j < 5; j++) cout << individuals[i].genes[j];
		cout << " ";
	}
	cout << endl;
}

Individual Population::GetFittest() {
	int maxFit = 0, currentFit = 0;
	int maxFitIndex = 0;

	for (int i = 0; i < populationSize; i++) {
		currentFit = individuals.at(i).fitness;
		if (maxFit < currentFit) {
			maxFit = currentFit;
			maxFitIndex = i;
		}
	}

	return individuals.at(maxFitIndex);
}


Individual Population::GetSecondFittest() {
	int maxFitIndex1 = 0, maxFitIndex2 = 0;
	int currentFit = 0, maxFit1 = 0, maxFit2 = 0;

	for (int i = 0; i < populationSize; i++) {
		currentFit = individuals.at(i).fitness;
		if (maxFit1 < currentFit) {
			maxFit2 = maxFit1;
			maxFit1 = currentFit;
			maxFitIndex2 = maxFitIndex1;
			maxFitIndex1 = i;
		} else if (currentFit > maxFit2) {
			maxFit2 = currentFit;
			maxFitIndex2 = i;
		}
	}

	return individuals.at(maxFitIndex2);
}

int Population::GetLeastFittestIndex() {
	int minFitIndex = 0;
	int minFit = individuals.at(0).fitness, currentFit;

	for (int i = 1; i < populationSize; i++) {
		currentFit = individuals.at(i).fitness;
		if (currentFit < minFit) {
			minFitIndex = i;
			minFit = currentFit;
		}
	}

	return minFitIndex;
}

void Population::RecalculateFitness() {
	for (int i = 0; i < populationSize; i++) {
		individuals.at(i).CalcFitness();
	}
}

