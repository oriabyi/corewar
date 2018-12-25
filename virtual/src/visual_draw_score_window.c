#include "../includes/corewar_header.h"

void 			print_state(t_corewar *core, int pos_y)
{
	if (core->ncur.pause)
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 1, "  _____  _______ _     _ _______ _______\n"
													 "  |_____] |_____| |     | |______ |______\n"
													 "  |       |     | |_____| ______| |______\n"
													 "                                        ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));

	}
	else
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 1, "  _____         _______ __   __ _____ __   _  ______\n"
													 "  |_____] |      |_____|   \\_/     |   | \\  | |  ____\n"
													 "  |       |_____ |     |    |    __|__ |  \\_| |_____|\n"
													 "                                                    ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
	}
	wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
}

void 			print_speed_bar(t_corewar *core, int pos_y)
{
	int 		i;

	i = 0;
	mvwprintw(core->ncur.score_window, pos_y, 1, "Speed: [");
	while (i < 20)
	{
		if (i < core->ncur.draw_speed / 5)
			wprintw(core->ncur.score_window, "#");
		else
			wprintw(core->ncur.score_window, "-");
		i++;
	}
	wprintw(core->ncur.score_window, "]  %d%%", core->ncur.draw_speed);
}

int 			print_players(t_corewar *core, int pos_y)
{
	int 		i;

	pos_y += 2;
	i = 0;
	while(i < core->qua_champs)
	{
		mvwprintw(core->ncur.score_window, pos_y, 1, "Player %d: ", i + 1);
		simple_print(core->ncur.score_window, i + 1);
		wprintw(core->ncur.score_window, "%s\n", core->champs[i].name);
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
		wprintw(core->ncur.score_window, "   Last live : 0\n");
		wprintw(core->ncur.score_window, "   Lives in current period : 0\n");
		pos_y += 6;
		i++;
	}
	return (pos_y);
}

void 			draw_score_window(t_corewar *core, int cycle)
{
	int 		pos_y;

	pos_y = 1;
	werase(core->ncur.score_window);
	print_state(core, pos_y);
	pos_y += 4;
	mvwprintw(core->ncur.score_window, pos_y, 1, "Cycles: %d", cycle);
	pos_y += 3;
	print_speed_bar(core, pos_y);
	pos_y += 2;
	if (core->ncur.pressed_button > 0)
		mvwprintw(core->ncur.score_window, pos_y, 1, "Pressed button: \"%c\" code: %d", core->ncur.pressed_button, core->ncur.pressed_button);
	pos_y = print_players(core, pos_y) + 2;
	mvwprintw(core->ncur.score_window, pos_y, 0, "   CYCLE_TO_DIE : %d", core->cycle_to_die);
	mvwprintw(core->ncur.score_window, ++pos_y, 0, "   CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(core->ncur.score_window, ++pos_y, 0, "   MAX_CHECKS : %d", MAX_CHECKS);
	pos_y += 4;
	mvwprintw(core->ncur.score_window, ++pos_y, 3, "Type cycle to go : %s", core->ncur.cycle_to_go);
	if (!core->ncur.pause)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(core->ncur.score_window, 0, 0);
	wrefresh(core->ncur.score_window);
}