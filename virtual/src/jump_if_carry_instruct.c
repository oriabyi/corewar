#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_carriage *carriage,
							  unsigned id)
{
	int 	jump;

	if (bigmother > 5475 && CUR_COORD > 3700)
		write(0,0,0);
	if (CARRY == 0)
	{
		return (1);
	}
	jump = (short)get_arguments(field, 0x80, FIRST_ARG, carriage);
	move_carriage(field, id, jump, carriage);
	denote_field(field, CUR_COORD);
	return (0);
}