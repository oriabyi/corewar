#include "../includes/corewar_header.h"


unsigned char 	 get_argument(t_cell *cell, t_bot *bot, int num_of_argument)
{
	return ((unsigned char)ft_ahtoi((char *)cell[CUR_POS
								  + num_of_argument].hex));
}

#include "../../libft/int_to_char_hex.c"

int 	write_in_cell(t_cell *cell, int position, t_bot *bot, int t_reg)
{

	char **str;
	int 	counter;

	counter = 0;
	str = int_to_char_hex(REG[t_reg], 4); //define 5
	if (!str)
		return (1); // return an ERROR
	while (str[counter])
	{
		position = (int)correction_coordinates(position);
		ft_strncpy((char *)cell[position].hex, str[counter], 2);
		if (!(CR_IS_VIEW_CARRIAGE(cell[position].bot_id))) // denote color
			cell[position].bot_id = get_id_of_bot(bot->id) + DENOTE_ALTERED;
		cell[position].time = SHOW_CHANGED_CYCLES;
		position++;
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


int 					get_regs_value(int argument, t_bot *bot, int type, int num, ...)
{
	int 				check_code;
	va_list 			ap;
	ssize_t 			*temp_reg;
	int 				position;

	va_start(ap, num);
	check_code = 0;
	while (num)
	{
		position = va_arg(ap, int);
		temp_reg = va_arg(ap, ssize_t *);
		if (check_instruction_arg(get_part_argument(argument, position), type) == 0)
		{
			if (check_reg((int)(*temp_reg)))
				check_code = 1;
			*temp_reg = REG[*temp_reg];
		}
		num--;
	}
	va_end(ap);
	return (check_code);
}

void 	store_index_instruct(t_cell *cell, t_bot *bot)	//label size == 2
{
	int 			argument;
	ssize_t 		position;
	ssize_t		 	first_arg;
	ssize_t 		second_arg;
	ssize_t			third_arg;

	argument = get_argument(cell, bot, 1);
	if (check_instruction_args(argument,
			T_REG, (T_REG | T_DIR | T_IND), (T_REG | T_DIR)) == ERROR)
	{
		return ;
	}

	first_arg = get_arguments(cell, bot, argument, FIRST_ARG);
	second_arg = get_arguments(cell, bot, argument, SECOND_ARG);
	third_arg = get_arguments(cell, bot, argument, THIRD_ARG);

	if (get_regs_value(argument, bot, T_REG, 2, 1, &second_arg, 2, &third_arg) == 1)
		return ;

	position = (((second_arg + third_arg) % IDX_MOD) + CUR_POS);

	write_in_cell(cell, (int)position, bot, (int)first_arg);
}








