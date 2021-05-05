#include <vector>
#include <stdint.h>

using namespace std;

class Individual {
    vector<vector<uint8_t>> grid;
    uint8_t fitness;

public:
    Individual (vector<vector<uint8_t>> &bone);
};