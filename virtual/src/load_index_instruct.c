#include "../includes/corewar_header.h"

ssize_t 		write_from_cell(t_cell *cell, int handicap, int bytes)
{
	int 		temp_bytes;
	char 		*temp;
	ssize_t		result;

	result = 0;
	temp = NULL;
	temp_bytes = bytes;
	while (temp_bytes--)
	{
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp, (char *)cell[handicap].hex); //TODO: CHECK ME, ne ti barannik, eto ya sebe
		handicap++;
	}
	if (bytes == 1)
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == 2)
		result = (short)ft_ahtoi(temp);
	else if (bytes == 4)
		result = ft_ahtoi(temp);

	free(temp);
	return (result);
}



void 	load_index_instruct(t_cell *cell, t_bot *bot) // label size == 2
{
	int 		argument;
	ssize_t 	position;
	ssize_t 	first_arg;
	ssize_t 	second_arg;
	unsigned char 	third_arg;

	position = 0;
	argument = get_argument(cell, bot, 1);
	if (check_instruction_args(argument,
					(T_REG | T_DIR | T_IND), (T_REG | T_DIR), T_REG) == ERROR)
	{
		return ;
	}

	first_arg = get_arguments(cell, bot, argument, FIRST_ARG);
	second_arg = get_arguments(cell, bot, argument, SECOND_ARG);
	third_arg = (unsigned char)get_arguments(cell, bot, argument, THIRD_ARG);

	if (check_type_arguments(argument, T_REG, 3, 0, first_arg, 2, second_arg, 3, third_arg) == 1)
		return ;


	if (COMMAND == CW_LDI)
	{
		position = ((first_arg + second_arg % IDX_MOD) + CUR_POS);
	}
	else if (COMMAND == CW_LLDI)
	{
		position = first_arg + second_arg + CUR_POS;
	}

	position = correction_coordinates(position);

	REG[third_arg] = (unsigned)write_from_cell(cell, (int)(position), FOUR_BYTES);

	if (COMMAND == CW_LLDI)
		change_carry_if_need(bot, third_arg);
}