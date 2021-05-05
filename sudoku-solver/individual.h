#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H

#include <vector>
#include <stdint.h>

using namespace std;

class Individual {
    vector<vector<uint8_t>> genome;
    uint32_t fitness;

public:
    Individual (vector<vector<uint8_t>> &bone);
    uint32_t calculateFitness (void);
};

#endif	// _INDIVIDUAL_H