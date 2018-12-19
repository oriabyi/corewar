#include "../includes/corewar_header.h"

void					load_instruct(t_cell *cell, t_bot *bot)
{
	int					argument;
	unsigned char		t_reg;
	unsigned			first_arg;

	argument = get_argument(cell, bot, 1);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		return ;
	}
	first_arg = (unsigned)get_arguments(cell, bot, argument, FIRST_ARG);
	t_reg = (unsigned char)get_arguments(cell, bot, argument, SECOND_ARG);

	if (check_reg(t_reg) == 1)
	{
		return ;
	}

	REG[t_reg] = first_arg;
	change_carry_if_need(bot, t_reg);
}
