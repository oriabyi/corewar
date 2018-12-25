#include "../includes/corewar_header.h"

void 	aff_instruct(t_carriage *carriage)
{
	write(1, (const void *)((ssize_t)(REG[CAR_FIRST_ARG] % 256)), 1);
}