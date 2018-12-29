/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_start_end_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:12:01 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:12:55 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void			visual_start(t_corewar *core)
{
	initscr();
	start_color();
	init_colors();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	cbreak();
	NCUR.memory_window =
		newwin(MEM_WIN_HEIGHT, MEM_WIN_WIDTH, 0, 0);
	NCUR.score_window =
		newwin(SCORE_WIN_HEIGHT, SCORE_WIN_WIDTH, 0,
			MEM_WIN_WIDTH + 1);
	refresh();
}

int				visual_end(t_corewar *core)
{
	wclear(NCUR.score_window);
	wclear(NCUR.memory_window);
	clear();
	echo();
	curs_set(1);
	endwin();
	return (0);
}
