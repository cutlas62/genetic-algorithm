#pragma once

#include <cstdlib>
#include <stdio.h>
#include <stdint.h>
#include <string>

class Individual
{
public:
	Individual (void);
    Individual(uint32_t genome_size);
    void print_genome(void);
    void calculate_fitness(const char *target, uint32_t target_size);
    void print_info(void);
    uint32_t get_fitness (void);
private:
    std::string genome;
    uint32_t fitness;

protected:

};

void generate_random_genome(std::string *genome, uint32_t size);