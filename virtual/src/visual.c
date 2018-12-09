#include "../includes/corewar_header.h"

int			vs_counter = 0;
unsigned	usleep_count = 30001;

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

void 			vs_start(t_corewar *core)
{
	initscr();			/* Start curses mode 	*/
	start_color();
	fill_colors();
	noecho();				//+
	curs_set(0); 			//+ switch off cursor
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	cbreak();
//	timeout(0);
}
//
//
int				reveal_memory_space(t_corewar *core, int cycle)
{
	unsigned i;
	i = 0;
	unsigned 	id;


	usleep(usleep_count);
	wrefresh(stdscr);

	int c = wgetch(stdscr);

	if (bigmother == 0)
		c = ' ';

	mvwprintw(stdscr, 0, 0, "Cycles: %d", cycle);
//	mvwprintw(stdscr, 0, 40, "speed: %u", usleep_count);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printw("\n");

//		c = wgetch(stdscr);

		if (c == ' ' || c == 'q' || c == 'r' || c == 'w' || c == 'e')
		{
			while (1)
			{
				c = wgetch(stdscr);
				if (c == ' ')
				{
					c = '\0';
					break ;
				} else 	if (c == 'w' && usleep_count - 5000 > 0)
					usleep_count -= 5000;
				else if (c == 'e')
					usleep_count += 5000;
				else if (c == 'q')
				{
					if  (usleep_count < 50000)
						usleep_count = 1;
					else
						usleep_count -= 50000;
					mvwprintw(stdscr, 0, 67, "speed: %u", usleep_count);
				}
				else if (c == 'r')
					usleep_count += 50000;
				else if (c == ESC)
					exit_message(core, 2, "Vse horosho, prosto esc!\n");
//				mvwprintw(stdscr, 0, 80, "PAUSE");
			}
		}
		else
		{
//			mvwprintw(stdscr, 0, 80, "WORKING");
		}




		id = get_id_of_bot(core->cell[i].bot_id);
		if (CR_IS_VIEW_SANE(core->cell[i].bot_id))
		{
			simple_print(id);
		}
		else if (CR_IS_VIEW_CARRIAGE(core->cell[i].bot_id)) // carriage
		{
			carriage_print(id);
		}
		else  if (CR_IS_VIEW_ALTERED(core->cell[i].bot_id))	// changed
		{
			altered_view(id);
			if (core->cell[i].time == 0)
				core->cell[i].bot_id = id;
			else
				(core->cell[i].time)--;
		}
		else  if (CR_IS_VIEW_ALIVE(core->cell[i].bot_id))	//alive
		{
			alive_view(id);
//			if (core->cell[i].time == 0)
//				core->cell[i].bot_id = id;
//			else
//				(core->cell[i].time)--;
		}

		printw("%s", core->cell[i].hex);
		attron(COLOR_PAIR(CR_CL_WHITE_BLACK));
		attroff(A_BOLD);
		printw(" ");
		i++;
	}

	wrefresh(stdscr);
	return (0);
}
/*int				reveal_memory_space(t_corewar *core, int cycle)
{
	int 		i;
	unsigned	id;

//	sleep(1);
	i = 0;

//	werase(core->ncur.memory_window);
	erase();
//	box(core->ncur.memory_window, 0, 0);

	move(1, 2);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
//			wprintw(core->ncur.memory_window, "\n");
			printw("\n");

		id = get_id_of_bot(core->cell[i].bot_id);
		if (CR_IS_VIEW_SANE(core->cell[i].bot_id))
		{
			simple_print(id);
		}
		else if (CR_IS_VIEW_CARRIAGE(core->cell[i].bot_id)) // carriage
		{
			carriage_print(id);
		}
		else  if (CR_IS_VIEW_ALTERED(core->cell[i].bot_id))	// changed
		{
			altered_view(id);
			if (core->cell[i].time == 0)
				core->cell[i].bot_id = id;
			else
				(core->cell[i].time)--;
		}
		else  if (CR_IS_VIEW_ALIVE(core->cell[i].bot_id))	//alive
		{
			alive_view(id);
//			if (core->cell[i].time == 0)
//				core->cell[i].bot_id = id;
//			else
//				(core->cell[i].time)--;
		}

		if (i % 64 == 0)
			move((i / 64) + 1, 1);





		attron(COLOR_PAIR(CR_CL_WHITE_BLACK));

//		wprintw(core->ncur.memory_window, "%s", core->cell[i].hex);

		printw("%s", core->cell[i].hex);


		attroff(A_BOLD);
//		wprintw(core->ncur.memory_window, " ");
		printw(" ");

		i++;
	}
//	wrefresh(core->ncur.memory_window);
	refresh();
	return (0);
}
*/
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
/*
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

//	core->ncur.memory_window = newwin(66, 193, 0, 0);
//	refresh();
//	core->ncur.memory_window = newwin(66, 30, 0, 68);
//	refresh();
}*/

int				vs_end(t_corewar *core)
{
	(void)core;
	echo();
	curs_set(1); 			//+ switch on cursor
	endwin();			/* End curses mode		*/
	return (0);
}


int				vs_init(t_corewar *core)
{
	int 	check_code;

	check_code = create_memory_space(core);
	if (check_code)
		check_correctness(core, check_code);

	fill_memory_space(core->bots, core->cell, core->qua_bots);
	return (0);
}
