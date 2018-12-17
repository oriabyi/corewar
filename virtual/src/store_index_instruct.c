#include "../includes/corewar_header.h"


int 	 get_argument(t_cell *cell, t_bot *bot, int num_of_argument)
{
	return (ft_ahtoi((char *)cell[bot->carriage->cur_pos
													+ num_of_argument].hex));
}

#include "../../libft/int_to_char_hex.c"

int 	write_in_cell(t_cell *cell, int position, t_bot *bot, int t_reg)
{

	char **str;
	int 	counter;

	counter = 0;
	str = int_to_char_hex(bot->carriage->registers[t_reg], 4); //define 5
	if (!str)
		return (ERROR); // return an ERROR
	while (str[counter])
	{
		ft_strncpy((char *)cell[position].hex, str[counter], 2);
		if (!(CR_IS_VIEW_CARRIAGE(cell[position].bot_id))) // denote color
			cell[position].bot_id = get_id_of_bot(bot->id) + DENOTE_ALTERED;
		cell[position].time = SHOW_CHANGED_CYCLES;
		position++;
		correction_coordinates(position);
		counter++;
	}
	free_char_matrix(str);
	return (0);
}

ssize_t 		correction_coordinates(ssize_t coordinate)
{
	if (coordinate >= MEM_SIZE)
	{
		coordinate %= MEM_SIZE;
	}
	while (coordinate < 0)
	{
		coordinate += MEM_SIZE;
	}
	return (coordinate);
}

static				int check_regs(t_cell *cell, t_bot *bot, int step, int argument)
{
	ssize_t 	temp;

	temp = 0;
	if ((GET_FIRST_ARGUMENT(argument) == T_REG && get_arg_reg(cell, bot, &step, &temp)) ||
		(GET_SECOND_ARGUMENT(argument) == T_REG && get_arg_reg(cell, bot, &step, &temp)) ||
		(GET_THIRD_ARGUMENT(argument) == T_REG && get_arg_reg(cell, bot, &step, &temp)))
	{
		return (ERROR);
	}
	return (0);
}

int 	store_index_instruct(t_cell *cell, t_bot *bot)	//label size == 2
{
	int 	argument;
	int 	step;
	ssize_t 	position;
	ssize_t 	t_reg;
	ssize_t 	temp;

	step = 1;
	position = 0;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			T_REG, (T_REG | T_DIR | T_IND), (T_REG | T_DIR)) == ERROR ||
						check_regs(cell, bot, step, argument) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 3, TWO_BYTES) + step, NOT_OWN);
		return (ERROR);
	}

	step += 1; // for skip first argument
	if (GET_SECOND_ARGUMENT(argument) == T_REG)
		get_arg_reg(cell, bot, &step, &position);
	else if (GET_SECOND_ARGUMENT(argument) == T_DIR)
		position = get_arg_dir(cell, bot, &step, TWO_BYTES);
	else if (GET_SECOND_ARGUMENT(argument) == GET_T_IND_ARG(argument))
		position = get_arg_ind(cell, bot, &step, IDX_MOD_ON);

	if (GET_THIRD_ARGUMENT(argument) == T_REG)
	{
		get_arg_reg(cell, bot, &step, &temp);
		position += temp;
	}
	else if (GET_THIRD_ARGUMENT(argument) == T_DIR)
	{
		position += get_arg_dir(cell, bot, &step, TWO_BYTES);
	}

	position = (position % IDX_MOD) + bot->carriage->cur_pos;
	position = correction_coordinates(position);

	t_reg = correction_coordinates(bot->carriage->cur_pos + 2);

	write_in_cell(cell, (int)position, bot,
			ft_ahtoi((char *)cell[t_reg].hex));

	move_carriage(cell, bot, step, NOT_OWN);
	return (0);
}








