/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw_memory_window.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:42:20 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:42:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void			print_cell(t_corewar *core, unsigned id, int i, int cycles)
{
	if (NCUR.carriage_pos == i || NCUR.highlight_coord == i)
		follow_view(NCUR.memory_window, NCUR, i);
	else if (core->field[i].is_alive == 2)
	{
		alive_view(NCUR.memory_window, id);
		if (core->field[i].live_cycles <= cycles)
		{
			core->field[i].live_cycles = -1;
			core->field[i].is_alive = 0;
		}
	}
	else if (core->field[i].carriages_on)
		carriage_print(NCUR.memory_window, id);
	else if (core->field[i].altered_cycles)
	{
		if (core->field[i].altered_cycles <= cycles)
		{
			core->field[i].altered_cycles = 0;
			core->field[i].champ_id = id;
		}
		altered_view(NCUR.memory_window, id);
	}
	else
		simple_print(NCUR.memory_window, id);
}

void			draw_memory_window(t_corewar *core, int cycles)
{
	int			i;

	i = 0;
	werase(NCUR.memory_window);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wprintw(NCUR.memory_window, "\n");
		print_cell(core, core->field[i].champ_id, i, cycles);
		if (i % 64 == 0)
			wmove(NCUR.memory_window, (i / 64) + 2, 3);
		wprintw(NCUR.memory_window, "%s", core->field[i].hex);
		wattron(NCUR.memory_window, COLOR_PAIR(CR_CL_GREY_BLACK));
		wattroff(NCUR.memory_window, A_BOLD);
		wprintw(NCUR.memory_window, " ");
		i++;
	}
	if (!NCUR.pause)
		wattron(NCUR.memory_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(NCUR.memory_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(NCUR.memory_window, 0, 0);
	wrefresh(NCUR.memory_window);
}
