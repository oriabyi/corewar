#include "../includes/corewar_header.h"

ssize_t			get_arguments(t_cell *cell, t_bot *bot, int argument, int number)
{
	ssize_t 	parameter;
	int			bytes;
	int 		main_arg;
	int			pos;
	int 		codage;

	main_arg = argument;
	bytes = get_dir_bytes(COMMAND);
	codage = get_codage(COMMAND);

	if (number == 0)
		argument = GET_FIRST_ARGUMENT(argument);
	else if (number == 1)
		argument = GET_SECOND_ARGUMENT(argument);
	else if (number == 2)
		argument = GET_THIRD_ARGUMENT(argument);

	if (argument == T_REG)
	{
		parameter = get_argument(cell, bot, 1 + codage + fishka(main_arg, number, bytes)) - 1;
		return ((unsigned char)parameter);
	}
	else if (argument ==  GET_T_IND_ARG(T_IND))
	{
		pos = (short)get_dir(cell, bot, 1 + codage + fishka(main_arg, number, bytes), TWO_BYTES);
		pos %= IDX_MOD;

		parameter = (unsigned)get_dir(cell, bot, fishka(main_arg, number, bytes) + pos, FOUR_BYTES);

		return ((unsigned)parameter);
	}
	else if (argument == T_DIR)
	{
		parameter = get_dir(cell, bot, 1 + codage + fishka(main_arg, number, bytes), bytes);
		if (bytes == 2)
			parameter = (short)parameter;
		else
			parameter = (unsigned)parameter;
		return (parameter);
	}
	return (0);
}

ssize_t 		get_dir(t_cell *cell, t_bot *bot, int handicap, int bytes)
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
		temp = ft_multjoinfr(3, NULL, temp,
							 (char *)cell[CUR_POS + handicap].hex);
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


ssize_t		get_arg_reg(t_cell *cell, t_bot *bot, int *step, ssize_t *get)
{
	int 		t_reg;
	ssize_t 	first_agg;

	t_reg = (unsigned char)(get_argument(cell, bot, *step) - 1);
	if (check_reg(t_reg))
		return (1);
	first_agg = REG[t_reg];
	*step += ONE_BYTE;
	*get = (unsigned)first_agg; // find type
	return (0);
}

ssize_t		get_arg_dir(t_cell *cell, t_bot *bot, int *step, int bytes)
{
	ssize_t 	first_agg;

	first_agg = get_dir(cell, bot, *step, bytes);
	*step += bytes;

	return (first_agg);
}


ssize_t		get_arg_ind(t_cell *cell, t_bot *bot, int *step, int code)
{
	ssize_t 	t_ind;


	t_ind = (short)get_dir(cell, bot, *step, TWO_BYTES);

	if (code == IDX_MOD_ON)
		t_ind %= IDX_MOD;
	t_ind = (unsigned)get_dir(cell, bot, (int)(*step + t_ind + CUR_POS), FOUR_BYTES);
	*step += TWO_BYTES;

	return (t_ind);
}
