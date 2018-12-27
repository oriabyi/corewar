#include "../includes/corewar_header.h"

void 	store_instruct(t_field *field, t_carriage *carriage, t_args *arguments) // label size == 4
{
	if (GET_SECOND_ARG(arguments->list_arguments) == T_REG)
	{
		REG[CAR_SECOND_ARG] = REG[CAR_FIRST_ARG];
	}
	else
	{
		write_in_field(field, (int)(CAR_SECOND_ARG + CUR_COORD),
				(unsigned char)CAR_FIRST_ARG, carriage); //TODO: dont sure that it has to be (int)
	}
}