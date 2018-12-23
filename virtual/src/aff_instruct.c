#include "../includes/corewar_header.h"

void 	aff_instruct(t_field *field, t_carriage *carriage, unsigned argument) // label size == 4
{
	unsigned char	t_reg;

	t_reg = (unsigned char)get_arguments(field, 0x40, FIRST_ARG, carriage);
	if (check_instruction_args(argument, T_REG, NONE_ARG, NONE_ARG) == ERROR)
	{
		return ;
	}
	write(1, (const void *)((ssize_t)(REG[t_reg] % 256)), 1);
}