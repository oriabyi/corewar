#include "../../includes/corewar_header.h"

void 	check_whose_id(t_corewar *core, unsigned id)
{
	unsigned 	counter;

	counter = 0;
	while (counter < core->qua_champs)
	{
		if ((unsigned)(-core->champs[counter].id) == id)
		{
			core->champs[counter].alive = true;
			core->last_live = counter;
		}
		counter++;
	}
}

void 	alive_instruct(t_field *field, t_carriage *carriage,
								t_corewar *core, t_args *arguments)
{
	check_whose_id(core, (unsigned)ARG_FIRST);
	field[CUR_COORD].champ_id =
			field[CUR_COORD].champ_id;
	field[CUR_COORD].altered_cycles = SHOW_CHANGED_CYCLES;
	ALIVE = true;
	core->qua_lives++;
}
