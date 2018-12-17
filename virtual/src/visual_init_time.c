#include "../includes/corewar_header.h"

void 				init_time(t_corewar *core)
{
	core->ncur.tstart.tv_nsec = 0;
	core->ncur.tstart.tv_sec = 0;
	core->ncur.tend.tv_nsec = 0;
	core->ncur.tend.tv_sec = 0;
}
