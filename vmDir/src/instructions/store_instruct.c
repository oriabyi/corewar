# include "../../includes/corewar_header.h"

void 	store_instruct(t_field *field, t_carriage *carriage, t_args *arguments,
					   unsigned cycles)
{
	if (GET_SECOND_ARG(LIST_ARGUMENTS) == T_REG)
	{
		REG[ARG_SECOND] = REG[ARG_FIRST];
	}
	else
	{
		write_in_field(field, (int)(ARG_SECOND + CUR_COORD),
					   REG[ARG_FIRST]); //TODO: dont sure that it has to be (int)
		add_champ_id((int)(ARG_SECOND + CUR_COORD), field, carriage, cycles);
	}
}