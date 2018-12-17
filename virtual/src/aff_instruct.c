#include "../includes/corewar_header.h"

int 	aff_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int			argument;
	int 		step;
	ssize_t		t_reg;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument, T_REG, NONE_ARG, NONE_ARG) == ERROR ||
								get_arg_reg(cell, bot, &step, &t_reg) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 1, TWO_BYTES) + 2, NOT_OWN);
		return (ERROR);
	}

	write(1, (const void *)((ssize_t)(t_reg % 256)), 1);
	move_carriage(cell, bot, 4, NOT_OWN);
	return (0);
}