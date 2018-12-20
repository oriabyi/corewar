#include "../includes/corewar_header.h"

void 			fill_rank(t_field *field, int cur_qua, int qua_inrank)
{
	if (cur_qua == qua_inrank)
		return ;
	else
		fill_rank(field, (++cur_qua), qua_inrank);
	field[cur_qua].bot_id = NOT_EXPOSED;
	field[cur_qua].sum_acts = 0;
	field[cur_qua].time = 0;
	field[cur_qua].old_owner = 0;
	field[cur_qua].hex[0] = '0';
	field[cur_qua].hex[1] = '0';
	field[cur_qua].hex[2] = '\0';
}

int 			create_memory_space(t_corewar *core)
{
	if (!(core->field = (t_field *)malloc(sizeof(t_field) * MEM_SIZE)))
		return (MEMORY_ERROR);
	fill_rank(core->field, 0, MEM_SIZE);
	return (0);
}