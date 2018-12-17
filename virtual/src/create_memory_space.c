#include "../includes/corewar_header.h"

void 			fill_rank(t_cell *cell, int cur_qua, int qua_inrank)
{
	if (cur_qua == qua_inrank)
		return ;
	else
		fill_rank(cell, (++cur_qua), qua_inrank);
	cell[cur_qua].bot_id = NOT_EXPOSED;
	cell[cur_qua].sum_acts = 0;
	cell[cur_qua].time = 0;
	cell[cur_qua].last_owner = 0;
	cell[cur_qua].hex[0] = '0';
	cell[cur_qua].hex[1] = '0';
	cell[cur_qua].hex[2] = '\0';
}

int 			create_memory_space(t_corewar *core)
{
	if (!(core->cell = (t_cell *)malloc(sizeof(t_cell) * MEM_SIZE)))
		return (MEMORY_ERROR);
	fill_rank(core->cell, 0, MEM_SIZE);
	return (0);
}