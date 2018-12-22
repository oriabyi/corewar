#include "../includes/corewar_header.h"

ssize_t 		write_from_field(t_field *field, int handicap, int bytes)
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
		temp = ft_multjoinfr(3, NULL, temp, (char *)field[handicap].hex);
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



void 	load_index_instruct(t_field *field, t_carriage *carriage, unsigned char argument) // label size == 2
{
	ssize_t 	coord;
	ssize_t 	first_arg;
	ssize_t 	second_arg;
	ssize_t 	third_arg;

	coord = 0;
	if (check_instruction_args(argument,
					(T_REG | T_DIR | T_IND), (T_REG | T_DIR), T_REG) == ERROR)
	{
		return ;
	}
	first_arg = get_arguments(field, argument, FIRST_ARG, carriage);
	second_arg = get_arguments(field, argument, SECOND_ARG, carriage);
	third_arg = get_arguments(field, argument, THIRD_ARG, carriage);
	if (check_type_arguments(argument, T_REG, 3, 0, first_arg, 1, second_arg, 2, third_arg) == 1)
		return ;
	if (COMMAND == CW_LDI)
		coord = (((first_arg + second_arg) % IDX_MOD) + CUR_COORD);
	else if (COMMAND == CW_LLDI)
		coord = first_arg + second_arg + CUR_COORD;
	coord = correction_coordinates(coord);
	REG[third_arg] = (unsigned)write_from_field(field, (int)(coord), FOUR_BYTES);
	if (COMMAND == CW_LLDI)
		change_carry_if_need((int)third_arg, carriage);
}