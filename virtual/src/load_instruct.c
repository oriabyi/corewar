#include "../includes/corewar_header.h"



ssize_t 		get_dir(t_cell *cell, t_bot *bot, int handicap, int bytes)
{
	int 		temp_bytes;
	char 		*temp;
	ssize_t		result;

	result = 0;
	temp = ft_strdup("");
	temp_bytes = bytes;
	while (temp_bytes--)
	{
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp,
				(char *)cell[bot->carriage->cur_pos + handicap].hex);
		handicap++;
	}
	if (bytes == ONE_BYTE)
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == TWO_BYTES)
		result = (short)ft_ahtoi(temp);
	else if (bytes == FOUR_BYTES)
		result = ft_ahtoi(temp);

	free(temp);
	return (result);
}


int			load_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	step;
	int 	t_reg;
	unsigned reg_value;

	step = 1;
	t_reg = 0;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN);
		return (ERROR);
	}

	if (GET_FIRST_ARGUMENT(argument) == T_DIR)
	{
		t_reg = get_argument(cell, bot, step + FOUR_BYTES); // check reg num
		reg_value = (unsigned)get_arg_dir(cell, bot, &step, FOUR_BYTES);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_THIRD_ARGUMENT(T_IND))
	{
		t_reg = get_argument(cell, bot, step + TWO_BYTES);
		reg_value =	(unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);
	}

	if (check_reg(bot, t_reg) == 1)
	{
		return (move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN));
	}
	bot->carriage->registers[t_reg] = reg_value;
	step++;
	change_carry_if_need(bot, t_reg);
	move_carriage(cell, bot, step, NOT_OWN);
	return (0);
}
