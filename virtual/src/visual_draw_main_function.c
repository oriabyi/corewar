#include "../includes/corewar_header.h"

unsigned 			get_id_of_champ(unsigned num)
{
	return ((num < 5) ? num : get_id_of_champ(num - 5)); // define 5
}

int 			display_windows(t_corewar *core, int cycle)
{
	draw_memory_window(core, cycle);
	draw_score_window(core, cycle);
	return (0);
}

int				draw(t_corewar *core, int cycle)
{
	int 		button;

	init_time(core);
	clock_gettime(CLOCK_MONOTONIC, &core->ncur.tstart);
	while (1)
	{
		///

		button = get_button(core, cycle);
		if (button == NEXT_CYCLE_BUTTON)
			return (cycle + 1);
		else if (button == ENTER_BUTTON)
		{
			if (ft_atoi(core->ncur.cycle_to_go) >= 0)
			{
				F_DUMP = (unsigned)ft_atoi(core->ncur.cycle_to_go); // TODO: do we need limit on this? default: False
				fill_input_field_with_zeros(core->ncur.cycle_to_go);
				if (F_DUMP < cycle)
				{
					reset_game(core);
					return (1); // TODO: first cycle is 'one'?
				}
				else
					return (cycle);
			}
		}

		///

		display_windows(core, cycle);
		clock_gettime(CLOCK_MONOTONIC, &core->ncur.tend);
		if (((double)core->ncur.tend.tv_sec + 1.0e-9*core->ncur.tend.tv_nsec) -
			((double)core->ncur.tstart.tv_sec + 1.0e-9*core->ncur.tstart.tv_nsec) > (1.0 - ((double)core->ncur.draw_speed / 100)))
		{
			if (!core->ncur.pause)
				break;
		}
		mvwprintw(core->ncur.score_window, 60, 3, "one way preparing took about %.5f seconds\n",
													((double)core->ncur.tend.tv_sec + 1.0e-9*core->ncur.tend.tv_nsec) -
													((double)core->ncur.tstart.tv_sec + 1.0e-9*core->ncur.tstart.tv_nsec));
		wrefresh(core->ncur.score_window);
	}

	return (cycle + 1);
}
