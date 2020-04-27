#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>


#include "individual.h"
#include "population.h"


#define POPULATION_SIZE     10000
#define N_GENERATIONS		1000
#define MUTATION_FACTOR		0.9

const char target_genome[] = {"Test String with many characters and weird stuff )(*&^%$#@"};
//const uint32_t target_genome_size = sizeof(target_genome);





using namespace std;
int main(int argc, char *argv[])
{
    srand (time(NULL));


    Population pop(POPULATION_SIZE, &target_genome[0], sizeof(target_genome));

    //pop.print_info();

    Individual *tmp;

    for(uint32_t i = 1; i < N_GENERATIONS + 1; i++)
    {
        tmp = pop.get_best_individual();
        pop.repopulate_next_gen (tmp->get_genome(), sizeof(target_genome));
        tmp = pop.get_best_individual();

        printf("Generation %d:\t", i);
        tmp->print_info();
    }


}

