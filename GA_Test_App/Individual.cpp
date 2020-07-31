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

string Individual::ToString() {
    string genesStr = "";

    for (int i = 0; i < geneLength; i++) {
        char c = genes[i] + '0';
        genesStr += c;
    }

    return genesStr;
}