#include "../includes/corewar_header.h"

int			vs_counter = 0;

// NORM VISUZUAL

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
		id = get_id_of_bot(core->cell[i].bot_id);
		if (CR_IS_VIEW_SANE(core->cell[i].bot_id))
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
		else if (CR_IS_VIEW_CARRIAGE(core->cell[i].bot_id)) // carriage
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
		else  if (CR_IS_VIEW_ALTERED(core->cell[i].bot_id))	//
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

			core->cell[i].bot_id -= DENOTE_ALTERED;
		}
		else  if (CR_IS_VIEW_ALIVE(core->cell[i].bot_id))
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


//		if (bigmother < 2700)// && vs_counter != 2841)
//			break ;
//		if (i == 160)
//			printf("%s!", core->cell[i].hex);
//		else
		printf("%s ", core->cell[i].hex);
//	printf("%-3X ", (unsigned)core->cell[i].hexb);
		i++;
	}
	printf("\n\n");

}

unsigned 			get_id_of_bot(unsigned num)
{
	return ((num < 5) ? num : get_id_of_bot(num - 5)); // define 5
}

void				init_cycle_to_go(t_corewar *core)
{
	ft_bzero(core->ncur.cycle_to_go, 7);
}


int 				uppend_cycle_to_go(t_corewar *core, char n)
{
	int				i;

	i = 0;
	while (i <= 5)
	{
		if (!core->ncur.cycle_to_go[i])
		{
			core->ncur.cycle_to_go[i] = n;
			core->ncur.cycle_to_go[i + 1] = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}

int 			delete_last_letter_cycle_to_go(t_corewar *core)
{
	int 		i;

	i = 0;
	while (i <= 5)
	{
		if (core->ncur.cycle_to_go[i] &&
			!core->ncur.cycle_to_go[i + 1])
		{
			core->ncur.cycle_to_go[i] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

void 			fill_memory_window(t_corewar *core)
{
	int 		i;
	unsigned	id;

	i = 0;

	werase(core->ncur.memory_window);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wprintw(core->ncur.memory_window, "\n");

		id = get_id_of_bot(core->cell[i].bot_id);

		if (CR_IS_VIEW_SANE(core->cell[i].bot_id))
			simple_print(core->ncur.memory_window, id);
		else if (CR_IS_VIEW_CARRIAGE(core->cell[i].bot_id)) // carriage
			carriage_print(core->ncur.memory_window, id);
		else  if (CR_IS_VIEW_ALTERED(core->cell[i].bot_id))	// changed
		{
			altered_view(core->ncur.memory_window, id);
			if (core->cell[i].time == 0)
				core->cell[i].bot_id = id;
			else
				(core->cell[i].time)--;
		}
		else  if (CR_IS_VIEW_ALIVE(core->cell[i].bot_id))	//alive
			alive_view(core->ncur.memory_window, id);

		if (i % 64 == 0)
			wmove(core->ncur.memory_window, (i / 64) + 1, 1);

		wprintw(core->ncur.memory_window, "%s", core->cell[i].hex);
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


int 			get_button(t_corewar *core, int cycle)
{
	int 		c;

	c = getch();

	if (c != -1)
		core->ncur.pressed_button = c;
	else
		return (0);

	if (c == PAUSE_BUTTON && core->ncur.pause)
		core->ncur.pause = FALSE;
	else if (ft_isdigit(c))
		uppend_cycle_to_go(core, (char)c);
	else if (c == DELETE_BUTTON)
		delete_last_letter_cycle_to_go(core);
	else if ((cycle == core->ncur.where_pause  || c == PAUSE_BUTTON) && !core->ncur.pause)
		core->ncur.pause = TRUE;
	else if (SPEED_PLUS_BUTTONS(c) && core->ncur.draw_speed < MAX_SPEED)
		core->ncur.draw_speed += SPEED_STEP;
	else if (SPEED_MINUS_BUTTONS(c) && core->ncur.draw_speed > MIN_SPEED)
		core->ncur.draw_speed -= SPEED_STEP;
	else if (c == VISUAL_OFF)			//??????????
	{
		core->flags.visual = FALSE;
		exit_message(core, 3, "ESCAPE!");
	}
	return (c);
}

void 			fill_score_window(t_corewar *core, int cycle)
{
	int 		i;

	werase(core->ncur.score_window);


	if (core->ncur.pause)
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "**********Pause************");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));

	}
	else
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "**********Playing**********");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
	}

	wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	mvwprintw(core->ncur.score_window, 5, 1, "Cycles: %d", cycle);


	mvwprintw(core->ncur.score_window, 8, 1, "Speed: [");
	i = 0;
	while (i < 20)
	{
		if (i < core->ncur.draw_speed / 5)
			wprintw(core->ncur.score_window, "#");
		else
			wprintw(core->ncur.score_window, "-");
		i++;
	}
	wprintw(core->ncur.score_window, "]  %d%%", core->ncur.draw_speed);


	if (core->ncur.pressed_button > 0)
		mvwprintw(core->ncur.score_window, 10, 1, "Pressed button: \"%c\" code: %d", core->ncur.pressed_button, core->ncur.pressed_button);


	i = 0;
	while(i < core->qua_bots)
	{
		mvwprintw(core->ncur.score_window, 12 + i + (i * 6), 1, "Player%d: ", i);
		simple_print(core->ncur.score_window, i + 1);
		wprintw(core->ncur.score_window, "%s\n", core->bots[i].name);
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
		wprintw(core->ncur.score_window, "   Last live : 0\n");
		wprintw(core->ncur.score_window, "   Lives in current period : 0\n");

		i++;
	}

	mvwprintw(core->ncur.score_window, i + 40, 0, "   CYCLE_TO_DIE : %d", 0);
	mvwprintw(core->ncur.score_window, i + 41, 0, "   CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(core->ncur.score_window, i + 42, 0, "   NBR_LIVE : ?");
	mvwprintw(core->ncur.score_window, i + 43, 0, "   MAX_CHECKS : %d", MAX_CHECKS);

//	mvwprintw(core->ncur.score_window, i + 45, 0, "   CYCLE_TO_GO : %s", core->ncur.cycle_to_go);


	if (core->ncur.pause)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(core->ncur.score_window, 0, 0);
	wrefresh(core->ncur.score_window);
}

int 			display_windows(t_corewar *core, int cycle)
{
	fill_memory_window(core);
	fill_score_window(core, cycle);
	return (0);
}

void 			reset_game(t_corewar *core, int cycle)
{
	int 		counter;

	counter = 0;
	while (counter < core->qua_bots)
	{
		clean_carriages(core->bots[counter].carriage);
		core->bots[counter].carriage = create_carriage(core->bots[counter].id);
		counter++;
	}
	free(core->cell);
	create_memory_space(core);
	fill_memory_space(core->bots, core->cell, core->qua_bots);
	core->max_checks = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
}

int				draw(t_corewar *core, int cycle)
{
	int 		button;

	init_time(core);
	clock_gettime(CLOCK_MONOTONIC, &core->ncur.tstart);
	while (1)
	{
		button = get_button(core, cycle);

		if (button == NEXT_CYCLE_BUTTON)
			break ;
		else if (button == ENTER_BUTTON)
		{
			if (ft_atoi(core->ncur.cycle_to_go) >= 0)
			{
				reset_game(core, cycle);
				core->flags.dump = (unsigned)ft_atoi(core->ncur.cycle_to_go);
				return (1);
			}
		}



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




//	refresh();
	return (cycle + 1);
}

void 			fill_rank(t_cell *cell, int cur_qua, int qua_inrank)
{
	if (cur_qua == qua_inrank)
		return ;
	else
		fill_rank(cell, (++cur_qua), qua_inrank);
	cell[cur_qua].bot_id = NOT_EXPOSED;
	cell[cur_qua].sum_acts = 0;
	cell[cur_qua].time = 0;
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

void 			vs_start(t_corewar *core)
{
	initscr();			// Start curses mode
	start_color();
	init_colors();
	noecho();				//+
	curs_set(0); 			//+ switch off cursor
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	cbreak();
	core->ncur.memory_window = newwin(66, 194, 0, 0);
	core->ncur.score_window = newwin(66, 70, 0, 195);
	refresh();
}

int				vs_end(t_corewar *core)
{
	(void)core;
	echo();
	curs_set(1); 			//+ switch on cursor
	endwin();			// End curses mode
	return (0);
}

int				vs_init(t_corewar *core)
{
	int 	check_code;


	core->ncur.pause = 1;
	core->ncur.pressed_button = 0;
	core->ncur.draw_speed = 100;
	core->ncur.where_pause = 0;
	init_cycle_to_go(core);
	check_code = create_memory_space(core);
	if (check_code)
		check_correctness(core, check_code);


	fill_memory_space(core->bots, core->cell, core->qua_bots);
	return (0);
}
