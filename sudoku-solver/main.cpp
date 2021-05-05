#include "population.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include <string>
#include <vector>

#define POP_N_INDIVIDUALS   1
#define POP_N_ALPHAS        5

using namespace std;

void populateBoneGenome (vector<vector<uint8_t>> &boneGenome) {
    ifstream inFile("in/example.txt");
    string tmp;
    int i = 0;
    while(getline(inFile, tmp)) {
        for (int j = 0; j < 9; j++) {
            boneGenome[i][j] = (tmp[j] - '0');
        }
        i++;
    }
    inFile.close();
}

int main() {

    // Initialize random seed
    srand(time(NULL));

    // Fill bone genome from txt file
    vector<vector<uint8_t>> boneGenome (9, vector<uint8_t>(9, 0));
    populateBoneGenome(boneGenome);

    // Create random population
    Population pop (boneGenome, POP_N_INDIVIDUALS, POP_N_ALPHAS);

    for (uint16_t i = 0; i < 1; i++){
        pop.repopulate(RANDOMIZE);
        cout << "Gen " << i << ": " << pop.getFitness() << endl;
    }


    return 0;
}