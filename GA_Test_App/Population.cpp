#include "Population.h"
using namespace std;

void Population::Print() {
	cout << "Printing population: ";
	for (int i = 0; i < this->populationSize; i++) {
		for (int j = 0; j < individuals.at(0).geneLength; j++) cout << individuals[i].genes[j];
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

void Population::Selection() {
	fittest = GetFittest();
	secondFittest = GetSecondFittest();
}

//assign random crossover point CP
//then take the fittest and second fittest individual
//and swap their genes indexed 0,1,2...CP
void Population::Crossover() {
	//choose a random point up to which all the genes will be swaped
	int crossoverPoint = rand() % individuals.at(0).geneLength;

	for (int i = 0; i < crossoverPoint; i++) {
		int temp = fittest.genes[i];
		fittest.genes[i] = secondFittest.genes[i];
		secondFittest.genes[i] = temp;
	}
}

//mutation where a random gene is flipped
//(mutation *always* occurs)
void Population::Mutation() {
	//select which gene will be mutated
	int mutationPoint = rand() % individuals.at(0).geneLength;

	if (0 == fittest.genes[mutationPoint]) {
		fittest.genes[mutationPoint] = 1;
	} else {
		fittest.genes[mutationPoint] = 0;
	}

	if (0 == secondFittest.genes[mutationPoint]) {
		secondFittest.genes[mutationPoint] = 1;
	}
	else {
		secondFittest.genes[mutationPoint] = 0;
	}
}

//we set the probability that each bit
//will be flipped 
//(mutation *sometimes* occurs)
void Population::Mutation(int probability) {
	//here we use two seperate loops to introduce more randomness
	int mutationProb;

	for (int i = 0; i < individuals.at(0).geneLength; i++) {
		mutationProb = rand() % 100;

		if (mutationProb < probability) {
			if (1 == fittest.genes[i]) {
				fittest.genes[i] = 0;
			} else {
				fittest.genes[i] = 1;
			}
		}
	}

	for (int i = 0; i < individuals.at(0).geneLength; i++) {
		mutationProb = rand() % 100;

		if (mutationProb < probability) {
			if (1 == secondFittest.genes[i]) {
				secondFittest.genes[i] = 0;
			}
			else {
				secondFittest.genes[i] = 1;
			}
		}
	}

}

Individual Population::GetFittestOffspring() {
	if (fittest.fitness > secondFittest.fitness) {
		return fittest;
	}
	return secondFittest;
}

void Population::AddFittestOffspring() {
	fittest.CalcFitness();
	secondFittest.CalcFitness();

	int leastFittestIndex = GetLeastFittestIndex();

	individuals.at(leastFittestIndex) = GetFittestOffspring();
}

void Population::PrintInfo() {
	cout << "Generation: " << generationCount << ", Fittest: " << fittest.ToString() << endl;
}

void Population::IncGen() {
	generationCount += 1;
}