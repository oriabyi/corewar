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

void 	load_index_instruct(t_field *field, t_carriage *carriage) // label size == 2
{
	ssize_t 	coord;

	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
					   FIRST_ARG, &CAR_FIRST_ARG,
					   SECOND_ARG, &CAR_SECOND_ARG) == 1)
	{
		return ;
	}
	if (COMMAND == CW_LDI)
	{
		coord = (((CAR_FIRST_ARG + CAR_SECOND_ARG) % IDX_MOD) + CUR_COORD);
	}
	else if (COMMAND == CW_LLDI)
	{
		coord = CAR_FIRST_ARG + CAR_SECOND_ARG + CUR_COORD;
	}
	coord = correction_coordinates(coord);
	REG[CAR_THIRD_ARG] = (unsigned)write_from_field(field, (int)(coord), FOUR_BYTES);
	if (COMMAND == CW_LLDI)
		change_carry_if_need((unsigned char)CAR_THIRD_ARG, carriage);
}