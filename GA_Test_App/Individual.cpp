#include "Individual.h"

void Individual::CalcFitness() {
    fitness = 0;
    for (int i = 0; i < geneLength; i++) {
        if (genes[i] == 1) {
            fitness++;
        }
    }
}

void Individual::PrintGenes() {
    for (int i = 0; i < geneLength; i++) {
        cout << genes[i];
    }
    cout << endl;
}
