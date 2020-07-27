#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class Individual {
public:
    int fitness = 0;
    int geneLength = 5;
    int genes[5] = { 0, 0, 0, 0, 0 };

    Individual() {
        //cout << "New individual: ";
        for (int i = 0; i < geneLength; i++) {
            genes[i] = rand() % 2;
            //cout << genes[i];
        }
        //cout << endl;
        CalcFitness();
    }

    void CalcFitness();
    void PrintGenes();
};