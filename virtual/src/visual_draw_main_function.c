#include "../includes/corewar_header.h"

int			vs_counter = 0;


void 			dog_nail_vs(t_corewar *core)
{
	unsigned i;
	i = 0;
	int 	id;
	printf("%d\n", vs_counter++);
	while (i < MEM_SIZE)
	{
		printf(RESET);
		if (i % 64 == 0)
			printf("\n  ");
		id = get_id_of_bot(core->field[i].bot_id);
		if (CR_IS_VIEW_SANE(core->field[i].bot_id))
		{
			if (id == NOONE)
				printf(RESET);
			else if (id == FIRST_BOT)
				printf(GREEN);
			else if (id == SECOND_BOT)
				printf(BLUE);
			else if (id == THIRD_BOT)
				printf(RED);
			else if (id == FOURTH_BOT)
				printf(CYAN);
		}
		else if (CR_IS_VIEW_CARRIAGE(core->field[i].bot_id)) // carriage
		{
			if (id == NOONE)
				printf(RESET);
			else if (id == FIRST_BOT)
				printf(BACK_GREEN);
			else if (id == SECOND_BOT)
				printf(L_BLUE);
			else if (id == THIRD_BOT)
				printf(L_RED);
			else if (id == FOURTH_BOT)
				printf(L_CYAN);
		}
		else  if (CR_IS_VIEW_ALTERED(core->field[i].bot_id))	//
		{
			if (id == NOONE)
				printf(RESET);
			else if (id == FIRST_BOT)
				printf(BLACK);
			else if (id == SECOND_BOT)
				printf(RED);
			else if (id == THIRD_BOT)
				printf(BLACK);
			else if (id == FOURTH_BOT)
				printf(RED);

			core->field[i].bot_id -= DENOTE_ALTERED;
		}
		else  if (CR_IS_VIEW_ALIVE(core->field[i].bot_id))
		{
			if (id == NOONE)
				printf(RESET);
			else if (id == FIRST_BOT)
				printf(BLACK);
			else if (id == SECOND_BOT)
				printf(RED);
			else if (id == THIRD_BOT)
				printf(BLACK);
			else if (id == FOURTH_BOT)
				printf(RED);
		}
		printf("%s ", core->field[i].hex);
		i++;
	}
	printf("\n\n");

}

unsigned 			get_id_of_bot(unsigned num)
{
	return ((num < 5) ? num : get_id_of_bot(num - 5)); // define 5
}

int 			display_windows(t_corewar *core, int cycle)
{
	draw_memory_window(core);
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
				core->flags.dump = (unsigned)ft_atoi(core->ncur.cycle_to_go); // TODO: do we need limit on this? default: False
				fill_input_field_with_zeros(core->ncur.cycle_to_go);
				if (core->flags.dump < cycle)
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
		mvwprintw(core->ncur.score_window, 40, 3, "one way preparing took about %.5f seconds\n",
				  ((double)core->ncur.tend.tv_sec + 1.0e-9*core->ncur.tend.tv_nsec) -
				  ((double)core->ncur.tstart.tv_sec + 1.0e-9*core->ncur.tstart.tv_nsec));
	}

	return (cycle + 1);
}
