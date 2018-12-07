#include "../includes/corewar_header.h"

void 	remove_carriage(t_cell *cell, unsigned id)
{
	if (cell->sum_acts == 0)
		cell->bot_id = get_id_of_bot(id);
	else
		cell->sum_acts--;
}

void 	place_carriage(t_cell *cell, unsigned id)
{
	if (CR_IS_VIEW_CARRIAGE(cell->bot_id))
	{
		cell->sum_acts++;
	}
	else
	{
		cell->bot_id = get_id_of_bot(id);
		if (cell->hex[0] == '0' && cell->hex[1] == '1')
			cell->bot_id += DENOTE_ALIVE;
		else
			cell->bot_id += DENOTE_CARRIAGE;
	}

}

void 	move_carriage(t_cell *cell, t_bot *bot, int step)
{
	remove_carriage(&cell[bot->carriage->cur_pos], bot->id);
	bot->carriage->cur_pos += step;
	place_carriage(&cell[bot->carriage->cur_pos], bot->id);
}

void 	change_carry_if_need(t_bot *bot, int position)
{
	if (bot->carriage->registers[position] == FALSE)
		bot->carriage->carry = TRUE;
	else
		bot->carriage->carry = FALSE;
}


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
		temp = ft_multjoinfr(3, NULL, temp, (char *)cell[bot->carriage->cur_pos + handicap].hex);
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


int 	load_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	step;
	int 	t_reg;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument, (T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
		return (ERROR);

	t_reg = get_argument(cell, bot, step + FOUR_BYTES); // there is shit huidu

	if (GET_FIRST_ARGUMENT(argument) == T_DIR)
	{
		bot->carriage->registers[t_reg] = (unsigned)get_arg_dir(cell, bot, &step, FOUR_BYTES);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_THIRD_ARGUMENT(T_IND))
	{
		bot->carriage->registers[t_reg] = (unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);
	}
	step++;
	change_carry_if_need(bot, t_reg);
	move_carriage(cell, bot, step);
	return (0);
}
