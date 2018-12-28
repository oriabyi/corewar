#include "../../includes/corewar_header.h"

void					load_instruct(t_carriage *carriage, t_args *arguments)
{
	REG[ARG_SECOND] = (unsigned)ARG_FIRST;
	change_carry_if_need((unsigned char)ARG_SECOND, carriage);
}
