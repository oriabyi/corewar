#include "../includes/corewar_header.h"

void simple_print(WINDOW *win, int id)
{
	if (id == NOONE)
	{
//		attron(A_BOLD);
		wattron(win, 48);
//		attron(COLOR_PAIR(CR_CL_WHITE_BLACK));
	}
	else if (id == FIRST_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_GREEN_BLACK));
	}
	else if (id == SECOND_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLUE_BLACK));
	}
	else if (id == THIRD_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_RED_BLACK));
	}
	else if (id == FOURTH_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_CYAN_BLACK));
	}
}


void 		carriage_print(WINDOW *win, int id)
{
	if (id == NOONE)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLACK_WHITE));
	}
	else if (id == FIRST_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLACK_GREEN));
	}
	else if (id == SECOND_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLACK_BLUE));
	}
	else if (id == THIRD_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLACK_RED));
	}
	else if (id == FOURTH_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_BLACK_CYAN));
	}
}

void 		altered_view(WINDOW *win, int id)
{
	wattron(win, A_BOLD);
	simple_print(win, id);
}

void 		alive_view(WINDOW *win, int id)
{
	wattron(win, A_BOLD);
	if (id == FIRST_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_WHITE_GREEN));
	}
	else if (id == SECOND_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_WHITE_BLUE));
	}
	else if (id == THIRD_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_WHITE_RED));
	}
	else if (id == FOURTH_BOT)
	{
		wattron(win, COLOR_PAIR(CR_CL_WHITE_CYAN));
	}
}

void 		follow_view(WINDOW *win, int id)
{
	wattron(win, COLOR_PAIR(CR_CL_BLACK_CYAN));
	carriage_print(win, id + 1);
}


