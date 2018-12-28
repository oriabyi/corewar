/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_set_memory_print_attr.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:06:45 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:06:51 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/corewar_header.h"

void		simple_print(WINDOW *win, int id)
{
	if (id == NOONE)
		wattron(win, COLOR_PAIR(CR_CL_GREY_BLACK));
	else if (id == FIRST_BOT)
		wattron(win, COLOR_PAIR(CR_CL_GREEN_BLACK));
	else if (id == SECOND_BOT)
		wattron(win, COLOR_PAIR(CR_CL_BLUE_BLACK));
	else if (id == THIRD_BOT)
		wattron(win, COLOR_PAIR(CR_CL_RED_BLACK));
	else if (id == FOURTH_BOT)
		wattron(win, COLOR_PAIR(CR_CL_CYAN_BLACK));
}

void		carriage_print(WINDOW *win, int id)
{
	if (id == NOONE)
		wattron(win, COLOR_PAIR(CR_CL_BLACK_WHITE));
	else if (id == FIRST_BOT)
		wattron(win, COLOR_PAIR(CR_CL_BLACK_GREEN));
	else if (id == SECOND_BOT)
		wattron(win, COLOR_PAIR(CR_CL_BLACK_BLUE));
	else if (id == THIRD_BOT)
		wattron(win, COLOR_PAIR(CR_CL_BLACK_RED));
	else if (id == FOURTH_BOT)
		wattron(win, COLOR_PAIR(CR_CL_BLACK_CYAN));
	else if (id == FOLLOW_CARRIAGE)
		wattron(win, COLOR_PAIR(CR_CL_YELLOW_BLACK));
}

void		altered_view(WINDOW *win, int id)
{
	wattron(win, A_BOLD);
	simple_print(win, id);
}

void		alive_view(WINDOW *win, int id)
{
	wattron(win, A_BOLD);
	if (id == FIRST_BOT)
		wattron(win, COLOR_PAIR(CR_CL_WHITE_GREEN));
	else if (id == SECOND_BOT)
		wattron(win, COLOR_PAIR(CR_CL_WHITE_BLUE));
	else if (id == THIRD_BOT)
		wattron(win, COLOR_PAIR(CR_CL_WHITE_RED));
	else if (id == FOURTH_BOT)
		wattron(win, COLOR_PAIR(CR_CL_WHITE_CYAN));
}

void		follow_view(WINDOW *win)
{
	wattron(win, COLOR_PAIR(CR_CL_BLACK_CYAN));
	carriage_print(win, FOLLOW_CARRIAGE);
}
