#include "../includes/corewar_header.h"

void				clean_carriages(t_carriage *carriage)
{
	if (carriage)
		clean_carriages(carriage->next);
	free(carriage);
}


void				clean_bots(t_bot *bots, unsigned quantity)
{
	int				counter;

	counter = 0;
	while (counter != quantity)
	{
		free(bots[counter].name);
		free(bots[counter].comment);
		free(bots[counter].exec_code);
		clean_carriages(bots[counter].carriage);
		// free carriages
		counter++;
	}
	free(bots);
}

void				clean_all(t_corewar *core)
{
//	clean_bots((core->bots), core->qua_bots);
//	if (core->cell)
//		free(core->cell);
}
