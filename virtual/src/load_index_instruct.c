#include "../includes/corewar_header.h"

ssize_t 		rename_me(t_cell *cell, t_bot *bot, int handicap, int bytes)
{
	int 		temp_bytes;
	char 		*temp;
	ssize_t		result;

	result = 0;
	temp = ft_strdup("");
	temp_bytes = bytes;
	while (temp_bytes--)
	{
		temp = ft_multjoinfr(3, NULL, temp, (char *)cell[handicap].hex);
		handicap++;
	}
	if (bytes == 1) // define ONE_BYTE etc..
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == 2)
		result = (short)ft_ahtoi(temp);
	else if (bytes == 4)
		result = ft_ahtoi(temp);

	free(temp);
	return (result);
}



int 	load_index_instruct(t_cell *cell, t_bot *bot) // label size == 2
{
	int 	argument;
	int 	step;
	ssize_t 	position;
	int 	num_of_reg;

	position = 0;
	step = 1;

	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			(T_REG | T_DIR | T_IND), (T_REG | T_DIR), T_REG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 3, TWO_BYTES) + step);
		return (ERROR);
	}

	if (GET_FIRST_ARGUMENT(argument) == T_REG)
		position = (unsigned long)get_arg_reg(cell, bot, &step);
	else if (GET_FIRST_ARGUMENT(argument) == T_DIR)
		position = (short)get_arg_dir(cell, bot, &step, TWO_BYTES);
	else if (GET_FIRST_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
		position = (unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);

	if (GET_SECOND_ARGUMENT(argument) == T_REG)
		position += (unsigned long)get_arg_reg(cell, bot, &step);
	else if (GET_SECOND_ARGUMENT(argument) == T_DIR)
		position += (short)get_arg_dir(cell, bot, &step, TWO_BYTES);

	if (bot->carriage->command == CW_LDI)
		position = ((position % IDX_MOD) + bot->carriage->cur_pos);
	else if (bot->carriage->command == CW_LLDI)
		position += bot->carriage->cur_pos;
	position = correction_coordinates(position);


	num_of_reg = (unsigned char)get_dir(cell, bot, step, ONE_BYTE);
	bot->carriage->registers[num_of_reg] =
			(unsigned)rename_me(cell, bot, (int)(position), FOUR_BYTES);

	if (bot->carriage->command == CW_LLDI)
		change_carry_if_need(bot, num_of_reg);
	move_carriage(cell, bot, ++step);
	return (0);
}