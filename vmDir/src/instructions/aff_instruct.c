#include "../../includes/corewar_header.h"

void 	aff_instruct(t_carriage *carriage, t_args *arguments)
{
	write(1, (const void *)((ssize_t)(REG[ARG_FIRST] % 256)), 1);
}