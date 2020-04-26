#include "individual.h"




const char genome_pool [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
                             ' ', '{', '}', '[', ']', '\\', '|', ';', ':', '"', ',', '.', '<', '>', '/', '?', '\''
                            };





Individual::Individual(uint32_t genome_size)
{
    generate_random_genome(&genome, genome_size);
}


void Individual::print_genome (void)
{
    for (uint16_t i = 0; i < genome.size(); i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void Individual::calculate_fitness (const char * target, uint32_t target_size)
{
    uint32_t tmp_fitness = 0;
    for(uint16_t i = 0; i < target_size; i++)
    {
        if (genome[i] != target[i])
        {
            tmp_fitness++;
        }
    }
    fitness = tmp_fitness;
}

void Individual::print_info(void)
{
    for (uint16_t i = 0; i < genome.size(); i++)
    {
        printf("%c", genome[i]);
    }
    printf("\tFitness: %d\n", fitness);
}

void generate_random_genome(std::string *genome, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        genome->push_back(genome_pool[rand() % sizeof(genome_pool)]);
    }
}