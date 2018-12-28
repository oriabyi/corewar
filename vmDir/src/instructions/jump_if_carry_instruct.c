#include "../../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_carriage *carriage, t_args *arguments)
{

	if (CARRY == 0)
	{
		return (1);
	}
	move_carriage(field, (int)(ARG_FIRST % IDX_MOD), carriage);
	denote_field(field, CUR_COORD);
	return (0);
}