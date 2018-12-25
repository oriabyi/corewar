#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_carriage *carriage, t_args *arguments)
{

	if (CARRY == 0)
	{
		return (1);
	}
	move_carriage(field, (int)CAR_FIRST_ARG, carriage); // TODO: int?
	denote_field(field, CUR_COORD);
	return (0);
}