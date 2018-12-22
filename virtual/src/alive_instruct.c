#include "../includes/corewar_header.h"

void 	alive_instruct(t_field *field, t_carriage *carriage, int id)
{
	unsigned 	t_dir;


	t_dir = (unsigned)get_arguments(field, 0x80, FIRST_ARG, carriage);

	if (t_dir == (unsigned)(-id))
		; // to champ jiv QUESTION

	field[CUR_COORD].old_owner = field[CUR_COORD].champ_id;

	field[CUR_COORD].champ_id =
			get_id_of_champ(field[CUR_COORD].champ_id) + DENOTE_ALIVE;
	field[CUR_COORD].time = SHOW_CHANGED_CYCLES;

	ALIVE = true;
}