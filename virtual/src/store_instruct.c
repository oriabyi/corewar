#include "../includes/corewar_header.h"

void 	store_instruct(t_field *field, t_carriage *carriage, unsigned char argument, unsigned id) // label size == 4
{
	int 		t_reg;
	ssize_t 	coord;
	ssize_t 	second_arg;

	t_reg = (unsigned char)get_arguments(field, argument, FIRST_ARG, carriage);
	second_arg = (unsigned)get_arguments(field, argument, SECOND_ARG, carriage);

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
		coord = (short)get_dir(field, 2 + fishka(argument, SECOND_ARG, 4), TWO_BYTES, carriage);

		write_in_field(field, (int)(coord + CUR_COORD), t_reg, carriage, id);
//		write_in_field(field, (int)(second_arg % IDX_MOD + CUR_COORD), champ, t_reg); it looks rightly
	}
}