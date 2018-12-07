#include "../includes/corewar_header.h"

void		simple_print(int id)
{
	if (id == NOONE)
	{
//		attron(A_BOLD);
		attron(48);
//		attron(COLOR_PAIR(CR_CL_WHITE_BLACK));
	}
	else if (id == FIRST_BOT)
	{
		attron(COLOR_PAIR(CR_CL_GREEN_BLACK));
	}
	else if (id == SECOND_BOT)
	{
		attron(COLOR_PAIR(CR_CL_BLUE_BLACK));
	}
	else if (id == THIRD_BOT)
	{
		attron(COLOR_PAIR(CR_CL_RED_BLACK));
	}
	else if (id == FOURTH_BOT)
	{
		attron(COLOR_PAIR(CR_CL_CYAN_BLACK));
	}
}


void 		carriage_print(int id)
{
	if (id == NOONE)
	{
		attron(COLOR_PAIR(CR_CL_BLACK_WHITE));
	}
	else if (id == FIRST_BOT)
	{
		attron(COLOR_PAIR(CR_CL_BLACK_GREEN));
	}
	else if (id == SECOND_BOT)
	{
		attron(COLOR_PAIR(CR_CL_BLACK_BLUE));
	}
	else if (id == THIRD_BOT)
	{
		attron(COLOR_PAIR(CR_CL_BLACK_RED));
	}
	else if (id == FOURTH_BOT)
	{
		attron(COLOR_PAIR(CR_CL_BLACK_CYAN));
	}
}

void 		altered_view(int id)
{
	attron(A_BOLD);
	simple_print(id);
}

void 		alive_view(int id)
{
	attron(A_BOLD);

	if (id == FIRST_BOT)
	{
		attron(COLOR_PAIR(CR_CL_WHITE_GREEN));
	}
	else if (id == SECOND_BOT)
	{
		attron(COLOR_PAIR(CR_CL_WHITE_BLUE));
	}
	else if (id == THIRD_BOT)
	{
		attron(COLOR_PAIR(CR_CL_WHITE_RED));
	}
	else if (id == FOURTH_BOT)
	{
		attron(COLOR_PAIR(CR_CL_WHITE_CYAN));
	}
}


