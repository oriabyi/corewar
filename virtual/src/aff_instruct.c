#include "../includes/corewar_header.h"

int 	aff_instruct(t_cell *cell, t_bot *bot)
{
	int			argument;
	int 		step;
	ssize_t	t_reg;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			T_REG, NONE_ARG, NONE_ARG) == ERROR)
		return (ERROR);

	t_reg = get_arg_reg(cell, bot, &step);
	write(1, (const void *)(t_reg % 256), 1);
	move_carriage(cell, bot, 4);
	return (0);
}