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
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp, (char *)cell[handicap].hex); //TODO: CHECK ME, ne ti barannik, eto ya sebe
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
	int 		argument;
	int 		step;
	ssize_t 	first;
	ssize_t 	position;
	ssize_t 	second;
	int 		num_of_reg;
	unsigned	t_reg;

	first = 0;
	step = 1;
	second = 0;
	position = 0;

	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
							   (T_REG | T_DIR | T_IND), (T_REG | T_DIR), T_REG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 3, TWO_BYTES) + step, NOT_OWN);
		return (ERROR);
	}

	if ((GET_FIRST_ARGUMENT(argument) == T_REG && get_arg_reg(cell, bot, &step, &first)) ||
		(GET_SECOND_ARGUMENT(argument) == T_REG && get_arg_reg(cell, bot, &step, &second)))
	{
		return (move_carriage(cell, bot, fishka(argument, 3, TWO_BYTES) + step, NOT_OWN));
	}
	else
	{
		step -= 2;
		if (GET_FIRST_ARGUMENT(argument) == T_REG)
		{
			if (first == 0)
				get_arg_reg(cell, bot, &step, &first);
		}
		else if (GET_FIRST_ARGUMENT(argument) == T_DIR)
		{
			first = (short)get_arg_dir(cell, bot, &step, TWO_BYTES);
		}
		else if (GET_FIRST_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
		{
			first = (unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);
		}
		position = first;

		if (GET_SECOND_ARGUMENT(argument) == T_REG)
		{
			if (second == 0)
				get_arg_reg(cell, bot, &step, &second);
		}
		else if (GET_SECOND_ARGUMENT(argument) == T_DIR)
		{
			first += (short)get_arg_dir(cell, bot, &step, TWO_BYTES);
		}
		position += second;
	}



	if (bot->carriage->command == CW_LDI)
	{
		position = ((position % IDX_MOD) + bot->carriage->cur_pos);
	}
	else if (bot->carriage->command == CW_LLDI)
	{
		position += bot->carriage->cur_pos;
	}

	position = correction_coordinates(position);


	num_of_reg = (unsigned char)get_dir(cell, bot, step, ONE_BYTE);
	bot->carriage->registers[num_of_reg] =
			(unsigned)rename_me(cell, bot, (int)(position), FOUR_BYTES);

	if (bot->carriage->command == CW_LLDI)
		change_carry_if_need(bot, num_of_reg);
	move_carriage(cell, bot, ++step, NOT_OWN);
	return (0);
}