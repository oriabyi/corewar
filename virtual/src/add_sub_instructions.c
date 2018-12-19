# include "../includes/corewar_header.h"

void					add_sub_instructs(t_cell *cell, t_bot *bot)
{
	unsigned char		third;
	unsigned char 		second;
	unsigned char		first;
	unsigned char		argument;

	argument = get_argument(cell, bot, 1);

	if (check_instruction_args(argument, T_REG, T_REG, T_REG) == ERROR)
	{
		return ;
	}
	first = (unsigned char)get_arguments(cell, bot, argument, FIRST_ARG);
	second = (unsigned char)get_arguments(cell, bot, argument, SECOND_ARG);
	third = (unsigned char)get_arguments(cell, bot, argument, THIRD_ARG);

	if (check_type_arguments(argument, T_REG, 3, 0, first, 1, second, 2, third) == 1)
	{
		return ;
	}

	REG[third] = which_operation_needs(REG[first], REG[second], COMMAND);
	change_carry_if_need(bot, third);
}
