#include "../includes/corewar_header.h"

void 				init_time(t_corewar *core)
{
	NCUR.tstart.tv_nsec = 0;
	NCUR.tstart.tv_sec = 0;
	NCUR.tend.tv_nsec = 0;
	NCUR.tend.tv_sec = 0;
}
