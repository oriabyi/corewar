#include "../includes/corewar_header.h"

int			vs_counter = 0;
unsigned	usleep_count = 30001;

//void 			dog_nail_vs(t_corewar *core)
//{
//	unsigned i;
//	i = 0;
//	int 	id;
//	printf("%d\n", vs_counter++);
//	while (i < MEM_SIZE)
//	{
//		printf(RESET);
//		if (i % 64 == 0)
//			printf("\n  ");
//		id = get_id_of_bot(core->cell[i].bot_id);
//		if (CR_IS_VIEW_SANE(core->cell[i].bot_id))
//		{
//			if (id == NOONE)
//				printf(RESET);
//			else if (id == FIRST_BOT)
//				printf(GREEN);
//			else if (id == SECOND_BOT)
//				printf(BLUE);
//			else if (id == THIRD_BOT)
//				printf(RED);
//			else if (id == FOURTH_BOT)
//				printf(CYAN);
//		}
//		else if (CR_IS_VIEW_CARRIAGE(core->cell[i].bot_id)) // carriage
//		{
//			if (id == NOONE)
//				printf(RESET);
//			else if (id == FIRST_BOT)
//				printf(BACK_GREEN);
//			else if (id == SECOND_BOT)
//				printf(L_BLUE);
//			else if (id == THIRD_BOT)
//				printf(L_RED);
//			else if (id == FOURTH_BOT)
//				printf(L_CYAN);
//		}
//		else  if (CR_IS_VIEW_ALTERED(core->cell[i].bot_id))	//
//		{
//			if (id == NOONE)
//				printf(RESET);
//			else if (id == FIRST_BOT)
//				printf(BLACK);
//			else if (id == SECOND_BOT)
//				printf(RED);
//			else if (id == THIRD_BOT)
//				printf(BLACK);
//			else if (id == FOURTH_BOT)
//				printf(RED);
//
//			core->cell[i].bot_id -= DENOTE_ALTERED;
//		}
//		else  if (CR_IS_VIEW_ALIVE(core->cell[i].bot_id))
//		{
//			if (id == NOONE)
//				printf(RESET);
//			else if (id == FIRST_BOT)
//				printf(BLACK);
//			else if (id == SECOND_BOT)
//				printf(RED);
//			else if (id == THIRD_BOT)
//				printf(BLACK);
//			else if (id == FOURTH_BOT)
//				printf(RED);
//		}
//
//
////		if (bigmother < 2700)// && vs_counter != 2841)
////			break ;
////		if (i == 160)
////			printf("%s!", core->cell[i].hex);
////		else
//		printf("%s ", core->cell[i].hex);
////	printf("%-3X ", (unsigned)core->cell[i].hexb);
//		i++;
//	}
//	printf("\n\n");
//
//}


void 			fill_colors(void)
{
	//simple colours
	init_pair(CR_CL_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);

	init_pair(CR_CL_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(CR_CL_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(CR_CL_RED_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(CR_CL_CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);


	init_pair(48, COLOR_WHITE, -1);
	//

	init_pair(44, COLOR_BLACK, COLOR_BLACK);

	//carriage colours
	init_pair(CR_CL_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);

	init_pair(CR_CL_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(CR_CL_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(CR_CL_BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(CR_CL_BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);

	//light colours
	init_pair(CR_CL_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);

	init_pair(CR_CL_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(CR_CL_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(CR_CL_BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(CR_CL_BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);

	//alive colours
	init_pair(CR_CL_WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(CR_CL_WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(CR_CL_WHITE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(CR_CL_WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);


}

unsigned 			get_id_of_bot(unsigned num)
{
	return ((num < 5) ? num : get_id_of_bot(num - 5)); // define 5
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
	box(core->ncur.memory_window, 0, 0);
	wrefresh(core->ncur.memory_window);
}


void 			get_button(t_corewar *core)
{
	int 		c;

	c = getch();

	if (c != -1)
		core->ncur.pressed_button = c;

	if (c == PAUSE && core->ncur.pause)
		core->ncur.pause = 0;
	else if (c == PAUSE && !core->ncur.pause)
		core->ncur.pause = 1;
	else if (c == SPEED_PLUS && core->ncur.draw_speed < 100)
		core->ncur.draw_speed += 5;
	else if (c == SPEED_MINUS && core->ncur.draw_speed > 0)
		core->ncur.draw_speed -= 5;
	else if (c == VISUAL_OFF)
		core->flags.visual = 0;
}

void 			fill_score_window(t_corewar *core, int cycle)
{
	int 		i;

	i = 0;

	werase(core->ncur.score_window);
	mvwprintw(core->ncur.score_window, 1, 1, "Cycles: %d", cycle);
	if (core->ncur.pause)
		mvwprintw(core->ncur.score_window, 2, getmaxx(core->ncur.score_window) / 2, "Pause");
	else
		mvwprintw(core->ncur.score_window, 2, getmaxx(core->ncur.score_window) / 2, "Playing");


	mvwprintw(core->ncur.score_window, 3, 1, "Speed: [");
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
		mvwprintw(core->ncur.score_window, 4, 1, "Pressed button: \"%c\" code: %d", core->ncur.pressed_button, core->ncur.pressed_button);


	box(core->ncur.score_window, 0, 0);
	wrefresh(core->ncur.score_window);
}

int				draw(t_corewar *core, int cycle)
{
	struct timespec tstart, tend;


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	while (1)
	{
		get_button(core);
		fill_score_window(core, cycle);
		clock_gettime(CLOCK_MONOTONIC, &tend);
		wrefresh(core->ncur.score_window);
		if (((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
			((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec) > (1.0 - ((double)core->ncur.draw_speed / 100)))
		{
			fill_memory_window(core);
			break;
		}
		mvwprintw(core->ncur.score_window, 10, 3, "one way preparing took about %.5f seconds\n",
				  ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
				  ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
	}




//	refresh();
	return (0);
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
	fill_colors();
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

	core->ncur.pause = 0;
	core->ncur.pressed_button = 0;
	core->ncur.draw_speed = 10;
	check_code = create_memory_space(core);
	if (check_code)
		check_correctness(core, check_code);

	fill_memory_space(core->bots, core->cell, core->qua_bots);
	return (0);
}
