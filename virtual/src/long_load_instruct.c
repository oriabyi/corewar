#include "../includes/corewar_header.h"

int					long_load_instruct(t_cell *cell, t_bot *bot) // label_size == 4, the same like ld
{
	int				argument;
	int				step;
	int				t_reg;
	short			t_int;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
		return (ERROR);


	if (GET_FIRST_ARGUMENT(argument) == T_DIR)
	{
		t_reg = get_argument(cell, bot, step + 4);
		bot->carriage->registers[t_reg] =
								(unsigned)get_dir(cell, bot, step, 2);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_THIRD_ARGUMENT(T_IND))
	{
		t_int = (short)get_dir(cell, bot, step, 2);
		t_reg = get_argument(cell, bot, step + 4);
		bot->carriage->registers[t_reg] =
								(unsigned)get_dir(cell, bot, step + t_int, 2);
	}
	else
		return (ERROR);
//	change_carry_if_need(bot, ft_ahtoi((const char *)(cell[bot->carriage->cur_pos + 6].hex)));
	change_carry_if_need(bot, get_argument(cell, bot, 6));
	move_carriage(cell, bot, step);
	return (0);
}