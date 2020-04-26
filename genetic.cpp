#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>
#include <iostream>

#define DNA_SIZE            sizeof(target_genome)
#define POPULATION_SIZE     100


const char genome_pool [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
                             ' ', '{', '}', '[', ']', '\\', '|', ';', ':', '"', ',', '.', '<', '>', '/', '?', '\''
                            };

const char target_genome[] = {"Test String with many characters and weird stuff )(*&^%$#@"};


void generate_random_genome(char *genome, uint32_t size);


class Individual
{
public:
    Individual();
    void print_genome(void);
    void calculate_fitness(void);
    void print_info(void);
private:
    char genome [DNA_SIZE];
    uint32_t fitness;

protected:

};


Individual::Individual(void)
{
    generate_random_genome(&genome[0], DNA_SIZE);
}


void Individual::print_genome (void)
{
    for (uint16_t i = 0; i < DNA_SIZE; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void Individual::calculate_fitness (void)
{
    uint32_t tmp_fitness = 0;
    for(uint16_t i = 0; i < DNA_SIZE; i++)
    {
        if (genome[i] != target_genome[i])
        {
            tmp_fitness++;
        }
    }
    fitness = tmp_fitness;
}

void Individual::print_info(void)
{
    for (uint16_t i = 0; i < DNA_SIZE; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\tFitness: %d\n", fitness);
}


void generate_random_genome(char *genome, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        genome[i] = genome_pool[rand() % sizeof(genome_pool)];
    }
}

using namespace std;
int main(int argc, char *argv[])
{
    srand (time(NULL));

    vector<Individual> population;

    for(uint32_t i = 0; i < POPULATION_SIZE; i++)
    {
        Individual tmp;
        tmp.calculate_fitness();
        population.push_back(tmp);
    }
    printf("population size: %lu\n", population.size());

    vector<Individual>::iterator ptr;
    for(ptr = population.begin(); ptr != population.end(); ptr++)
    {
        Individual tmp = *ptr;
        tmp.print_info();
    }

}

