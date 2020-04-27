#include "individual.h"




const char genome_pool [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
                             ' ', '{', '}', '[', ']', '|', ';', ':', '"', ',', '.', '<', '>', '/', '?'
                            };



Individual::Individual(void)
{

}


Individual::Individual(uint32_t genome_size)
{
    generate_random_genome(&genome, genome_size);
}

Individual::Individual (uint32_t genome_size, std::string * new_genome)
{
    for(uint32_t i = 0; i < genome_size; i++){
        genome.push_back(new_genome->at(i));
    }
}


void Individual::print_genome (void)
{
    for (uint16_t i = 0; i < genome.size(); i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void Individual::calculate_fitness (const char *target, uint32_t target_size)
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


uint32_t Individual::get_fitness(void)
{
    return fitness;
}

std::string *Individual::get_genome (void)
{
    return &genome;
}
void Individual::set_genome (std::string *new_genome)
{
    genome.clear();
    uint16_t genome_size = new_genome->size();
    for(uint16_t i = 0; i < genome_size; i++)
    {
        genome.push_back(new_genome->at(i));
    }
}



void generate_random_genome(std::string *genome, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        genome->push_back(genome_pool[rand() % sizeof(genome_pool)]);
    }
}


void generate_mutated_genome(std::string *genome, uint32_t size, std::string *prev_genome, double p)
{
    for(uint32_t i = 0; i < size; i++)
    {
        if(((double)rand() / RAND_MAX) < p)
        {
            genome->push_back(prev_genome->at(i));
        }
        else
        {
            genome->push_back(genome_pool[rand() % sizeof(genome_pool)]);
        }
    }
}

void mate (std::string *child_genome, uint32_t genome_size, std::string *parent_1_genome, std::string *parent_2_genome)
{
    child_genome->clear();
    for(uint16_t i = 0; i < genome_size; i++)
    {
        double rnd = (double)rand() / RAND_MAX;

        if(rnd < 0.1)
        {
            // (10%) New chomosome
            child_genome->push_back(genome_pool[rand() % sizeof(genome_pool)]);
        }
        else if (rnd < 0.55)
        {
            // (45%) Inherit chomosome from parent 1
            child_genome->push_back(parent_1_genome->at(i));
        }
        else
        {
            // (45%) Inherit chromosome from parent 2
            child_genome->push_back(parent_2_genome->at(i));
        }

    }
}

