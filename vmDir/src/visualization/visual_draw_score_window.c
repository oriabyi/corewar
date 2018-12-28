/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw_score_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:06:54 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/25 16:09:58 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int				print_state(t_corewar *core, int pos_y)
{
	if (NCUR.pause)
	{
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(NCUR.score_window, pos_y, 1,
			"  _____  _______ _     _ _______ _______\n"
			"  |_____] |_____| |     | |______ |______\n"
			"  |       |     | |_____| ______| |______\n"
			"                                        ");
		wattroff(NCUR.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	}
	else
	{
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(NCUR.score_window, pos_y, 1,
			"  _____         _______ __   __ _____ __   _  ______\n"
			"  |_____] |      |_____|   \\_/     |   | \\  | |  ____\n"
			"  |       |_____ |     |    |    __|__ |  \\_| |_____|\n"
			"                                                    ");
		wattroff(NCUR.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
	}
	wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	return (pos_y + 5);
}

int				print_speed_bar(t_corewar *core, int pos_y)
{
	int			i;

	i = 0;
	mvwprintw(NCUR.score_window, pos_y, 1, "Speed: [");
	while (i < 20)
	{
		if (i < NCUR.draw_speed / 5)
			wprintw(NCUR.score_window, "#");
		else
			wprintw(NCUR.score_window, "-");
		i++;
	}
	wprintw(NCUR.score_window, "]  %d%%", NCUR.draw_speed);
	return (pos_y + 2);
}

int				print_players(t_corewar *core, int pos_y)
{
	int			i;

	pos_y += 2;
	i = 0;
	while (i < core->qua_champs)
	{
		mvwprintw(NCUR.score_window, pos_y, 1, "Player %d: ", i + 1);
		simple_print(NCUR.score_window, i + 1);
		wprintw(NCUR.score_window, "%s\n", core->champs[i].name);
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
		wprintw(NCUR.score_window, "   Last live : %d\n", 0);
		wprintw(NCUR.score_window, "   Lives in current period : %d\n", 0);
		pos_y += 6;
		i++;
	}
	return (pos_y + 2);
}

int				print_game_info(t_corewar *core, int pos_y)
{
	mvwprintw(NCUR.score_window, pos_y, 1, "CYCLE_TO_DIE : %d",
			core->cycle_to_die);
	mvwprintw(NCUR.score_window, ++pos_y, 1, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(NCUR.score_window, ++pos_y, 1, "MAX_CHECKS : %d", MAX_CHECKS);
	pos_y += 4;
	return (pos_y);
}

void			draw_score_window(t_corewar *core, int cycle)
{
	int			pos_y;

	pos_y = 1;
	werase(NCUR.score_window);
	pos_y = print_state(core, pos_y);
	mvwprintw(NCUR.score_window, pos_y, 1, "Cycles: %d", cycle);
	pos_y += 2;
	pos_y = print_speed_bar(core, pos_y);
	mvwprintw(NCUR.score_window, ++pos_y, 1, "Carriages quantity: %d",
			core->quant_carriages);
	pos_y = print_players(core, pos_y);
	pos_y = print_game_info(core, pos_y);
	draw_menu(core, pos_y);
	if (!NCUR.pause)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(NCUR.score_window, 0, 0);
	wrefresh(NCUR.score_window);
}
