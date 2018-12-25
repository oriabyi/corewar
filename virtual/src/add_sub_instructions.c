# include "../includes/corewar_header.h"

void					add_sub_instructs(t_carriage *carriage)
{
	REG[CAR_THIRD_ARG] =
		which_operation_needs(REG[CAR_FIRST_ARG], REG[CAR_SECOND_ARG], COMMAND);
	change_carry_if_need((unsigned char)CAR_THIRD_ARG, carriage);
}
