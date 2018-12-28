# include "../includes/corewar_header.h"

void					add_sub_instructs(t_carriage *carriage, t_args *arguments)
{
	REG[ARG_THIRD] =
		which_operation_needs(REG[ARG_FIRST],
								REG[ARG_SECOND],
								I_COMMAND);
	change_carry_if_need((unsigned char)ARG_THIRD, carriage);
}
