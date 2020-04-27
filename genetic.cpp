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

const char target_genome[] = {"Test String with many characters and weird stuff )(*&^%$#@"};



int main(int argc, char *argv[])
{
    srand (time(NULL));


    Population pop(POPULATION_SIZE, &target_genome[0], sizeof(target_genome));

    //pop.print_info();

    Individual *tmp = new Individual;
    pop.sort_by_fitness();
    *tmp = (pop.get_population())->at(0);

    printf("Generation 0:\t");
        tmp->print_info();

    for(uint32_t i = 1; i < N_GENERATIONS; i++)
    {
        pop.repopulate_next_gen (tmp->get_genome(), sizeof(target_genome));
        pop.sort_by_fitness();
        *tmp = (pop.get_population())->at(0);

        printf("Generation %d:\t", i);
        tmp->print_info();
    }


}

