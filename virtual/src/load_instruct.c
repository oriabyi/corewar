#include "../includes/corewar_header.h"

void					load_instruct(t_carriage *carriage)
{
	REG[CAR_SECOND_ARG] = (unsigned)CAR_FIRST_ARG;
	change_carry_if_need((unsigned char)CAR_SECOND_ARG, carriage);
}
