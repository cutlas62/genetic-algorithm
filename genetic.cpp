#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>


#include "individual.h"
#include "population.h"


#define POPULATION_SIZE     100

const char target_genome[] = {"Test String with many characters and weird stuff )(*&^%$#@"};
//const uint32_t target_genome_size = sizeof(target_genome);





using namespace std;
int main(int argc, char *argv[])
{
    srand (time(NULL));

    Population pop(POPULATION_SIZE, &target_genome[0], sizeof(target_genome));
    
    pop.print_info();

}

