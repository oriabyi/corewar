#include "../includes/corewar_header.h"

void 	store_instruct(t_field *field, t_bot *bot) // label size == 4
{
	int 		argument;
	int 		t_reg;
	ssize_t 	coord;
	ssize_t 	second_arg;

	argument = get_argument(field, bot, 1);
	
	
	t_reg = (unsigned char)get_arguments(field, bot, argument, FIRST_ARG);
	second_arg = (unsigned)get_arguments(field, bot, argument, SECOND_ARG);

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
		coord = (short)get_dir(field, bot, 2 + fishka(argument, SECOND_ARG, 4), TWO_BYTES);

		write_in_field(field, (int)(coord + CUR_COORD), bot, t_reg);
//		write_in_field(field, (int)(second_arg % IDX_MOD + CUR_COORD), bot, t_reg); it looks rightly
	}
}