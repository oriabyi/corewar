#include "../includes/corewar_header.h"

void 			draw_memory_window(t_corewar *core)
{
	int 		i;
	unsigned	id;

	i = 0;

	werase(core->ncur.memory_window);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wprintw(core->ncur.memory_window, "\n");

		id = get_id_of_bot(core->field[i].bot_id);

		if (CR_IS_VIEW_SANE(core->field[i].bot_id))
			simple_print(core->ncur.memory_window, id);
		else if (CR_IS_VIEW_CARRIAGE(core->field[i].bot_id)) // carriage
			carriage_print(core->ncur.memory_window, id);
		else  if (CR_IS_VIEW_ALTERED(core->field[i].bot_id))	// changed
		{
			altered_view(core->ncur.memory_window, id);
			if (core->field[i].time == 0)
				core->field[i].bot_id = id;
			else
				(core->field[i].time)--;
		}
		else  if (CR_IS_VIEW_ALIVE(core->field[i].bot_id))	//alive
			alive_view(core->ncur.memory_window, id);

		if (i % 64 == 0)
			wmove(core->ncur.memory_window, (i / 64) + 1, 1);

		wprintw(core->ncur.memory_window, "%s", core->field[i].hex);
		wattron(core->ncur.memory_window, COLOR_PAIR(CR_CL_WHITE_BLACK));
		wattroff(core->ncur.memory_window, A_BOLD);
		wprintw(core->ncur.memory_window, " ");
		i++;
	}
	if (!core->ncur.pause)
		wattron(core->ncur.memory_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(core->ncur.memory_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(core->ncur.memory_window, 0, 0);
	wrefresh(core->ncur.memory_window);
}
