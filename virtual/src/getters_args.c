#include "../includes/corewar_header.h"

ssize_t			get_arguments(t_field *field, int argument, int number, t_carriage *carriage)
{
	ssize_t 	parameter;
	int			bytes;
	int 		main_arg;
	int			pos;
	int 		codage;

	main_arg = argument;
	bytes = get_dir_bytes(COMMAND); // move it to struct
	codage = get_codage(COMMAND);	// and this

	if (number == 0)
		argument = GET_FIRST_ARG(argument);
	else if (number == 1)
		argument = GET_SECOND_ARG(argument);
	else if (number == 2)
		argument = GET_THIRD_ARG(argument);

	if (argument == T_REG)
	{
		parameter = get_argument(field, CUR_COORD + 1 + codage + get_indent(main_arg, number, bytes)) - 1;
		return ((unsigned char)parameter);
	}
	else if (argument ==  GET_T_IND_ARG(T_IND))
	{
		pos = (short)get_dir(field, 1 + codage + get_indent(main_arg, number, bytes), TWO_BYTES, carriage);
		if (COMMAND != CW_LLD)
			pos %= IDX_MOD;
		if (COMMAND == CW_ST)
			return ((short)pos);
		parameter = (unsigned)get_dir(field, pos, FOUR_BYTES, carriage);
		return ((unsigned)parameter);
	}
	else if (argument == T_DIR)
	{
		parameter = get_dir(field, 1 + codage + get_indent(main_arg, number, bytes), bytes, carriage);
		if (bytes == 2)
			parameter = (short)parameter;
		else
			parameter = (unsigned)parameter;
		return (parameter);
	}
	return (0);
}

ssize_t 		get_dir(t_field *field, int handicap, int bytes, t_carriage *carriage) // swap to CUR_CORD  + handicap
{
	int 		temp_bytes;
	char 		*temp;
	ssize_t		result;

	result = 0;
	temp = NULL;
	temp_bytes = bytes;
	handicap += CUR_COORD;
	while (temp_bytes--)
	{
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp,
							 (char *)field[handicap].hex);
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
