#include "../includes/corewar_header.h"

void				long_load_instruct(t_cell *cell, t_bot *bot) // label_size == 4, the same like ld
{
	int				argument;
	int				step;
	int				t_reg;
	short			t_int;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		return ;
	}


	if (GET_FIRST_ARGUMENT(argument) == T_DIR)
	{
		t_reg = get_argument(cell, bot, step + 4);
		REG[t_reg] =
								(unsigned)get_dir(cell, bot, step, 2);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
	{
		t_int = (short)get_dir(cell, bot, step, 2);
		t_reg = get_argument(cell, bot, step + 4);
		REG[t_reg] =
								(unsigned)get_dir(cell, bot, step + t_int, 2);
	}
	else
		return ;

//	change_carry_if_need(bot, ft_ahtoi((const char *)(cell[CUR_POS + 6].hex)));
	change_carry_if_need(bot, get_argument(cell, bot, 6));
}