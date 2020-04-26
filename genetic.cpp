#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>
#include <vector>

#define DNA_SIZE	sizeof(target_genome)


const char genome_pool [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',	
                             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',	
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', 
                             ' ', '{', '}', '[', ']','\\', '|', ';', ':', '"', ',', '.', '<', '>', '/', '?', '\''
                            };

const char target_genome[] = {"carapala comecocos"};


void generate_random_genome(char *genome, uint32_t size);


class Individual
{
public:
    Individual();
    void print_genome(void);
    void calculate_fitness(void);
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

void Individual::calculate_fitness (void){
	uint32_t tmp_fitness = 0;
	for(uint16_t i = 0; i < DNA_SIZE; i++){
		if (genome[i] != target_genome[i]){
			tmp_fitness++;
		}
	}
	fitness = tmp_fitness;
	printf("fitness = %d\n", fitness);
}


void generate_random_genome(char *genome, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        genome[i] = genome_pool[rand() % sizeof(genome_pool)];
    }
}


int main(int argc, char *argv[])
{
    srand (time(NULL));
    

    Individual a;
    a.print_genome();
    a.calculate_fitness();
}

