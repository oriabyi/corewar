#include "../includes/corewar_header.h"

void 			visual_start(t_corewar *core)
{
	initscr();			// Start curses mode
	start_color();
	init_colors();
	noecho();				//+
	curs_set(0); 			//+ switch off cursor
	keypad(stdscr, true);
	nodelay(stdscr, true);
	cbreak();
	core->ncur.memory_window = newwin(66, 194, 0, 0);
	core->ncur.score_window = newwin(66, 70, 0, 195);
	refresh();
}

int				visual_end(t_corewar *core)
{
	(void)core;
	echo();
	curs_set(1); 			//+ switch on cursor
	endwin();			// End curses mode
	return (0);
}