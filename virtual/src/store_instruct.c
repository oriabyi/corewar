#include "../includes/corewar_header.h"

void 	store_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 		argument;
	int 		t_reg;
	ssize_t 	position;
	ssize_t 	second_arg;

	argument = get_argument(cell, bot, 1);
	
	
	t_reg = (unsigned char)get_arguments(cell, bot, argument, FIRST_ARG);
	second_arg = (unsigned)get_arguments(cell, bot, argument, SECOND_ARG);

	if (check_reg(t_reg) || check_instruction_args(argument,
			(T_REG), (T_REG | T_IND), (NONE_ARG)) == ERROR)
	{
		return ;
	}

	if (GET_SECOND_ARGUMENT(argument) == T_REG)
	{
		if (check_reg(t_reg) == 0)
			REG[second_arg] = REG[t_reg];
	}
	else
	{
		position = (short)get_dir(cell, bot, 2 + fishka(argument, SECOND_ARG, 4), TWO_BYTES);

		write_in_cell(cell, (int)(position + CUR_POS), bot, t_reg);
//		write_in_cell(cell, (int)(second_arg % IDX_MOD + CUR_POS), bot, t_reg); it looks rightly
	}
}