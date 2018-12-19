#include "../includes/corewar_header.h"

void 	aff_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int			argument;
	int 		step;
	ssize_t		t_reg;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument, T_REG, NONE_ARG, NONE_ARG) == ERROR ||
								get_arg_reg(cell, bot, &step, &t_reg) == ERROR)
	{
		return ;
	}

	write(1, (const void *)((ssize_t)(t_reg % 256)), 1);
}