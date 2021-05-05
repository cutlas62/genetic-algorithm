#include "individual.h"
#include <stdlib.h>

Individual::Individual (vector<vector<uint8_t>> &bone) {
    // Fill grid randomly according to the boneGenome
    for(uint8_t i = 0; i < 9; i++) {
        for(uint8_t j = 0; j < 9; j++) {
            if (bone[i][j] == 0) {
                genome[i][j] = rand() % 9 + 1;	// Values from 1 to 9
            } else {
                genome[i][j] = bone[i][j];
            }
        }
    }

    // Set the initial fitness to the worst possible value
    fitness = 255;
}