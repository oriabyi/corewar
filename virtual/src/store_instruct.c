#include "../includes/corewar_header.h"

void 	store_instruct(t_field *field, t_carriage *carriage, t_args *arguments,
					   unsigned cycles)
{
	if (GET_SECOND_ARG(LIST_ARGUMENTS) == T_REG)
	{
		REG[CAR_SECOND_ARG] = REG[CAR_FIRST_ARG];
	}
	else
	{
		write_in_field(field, (int)(CAR_SECOND_ARG + CUR_COORD),
					   REG[CAR_FIRST_ARG]); //TODO: dont sure that it has to be (int)
		add_champ_id((int)(CAR_SECOND_ARG + CUR_COORD), field, carriage, cycles);
	}
}