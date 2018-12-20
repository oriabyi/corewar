#include "../includes/corewar_header.h"

void 	aff_instruct(t_field *field, t_bot *bot) // label size == 4
{
	int				argument;
	unsigned char	t_reg;

	t_reg = (unsigned char)get_arguments(field, bot, 0x40, FIRST_ARG);
	argument = get_argument(field, bot, 1);

	if (check_instruction_args(argument, T_REG, NONE_ARG, NONE_ARG) == ERROR)
	{
		return ;
	}

	write(1, (const void *)((ssize_t)(REG[t_reg] % 256)), 1);
}