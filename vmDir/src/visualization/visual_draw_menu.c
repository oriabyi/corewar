/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:16:43 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:16:44 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

int				draw_fields(t_corewar *core, int pos_y)
{
	if (NCUR.current_field == NCUR.cycle_to_go)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Cycle to go : %s",
			NCUR.cycle_to_go);
	if (NCUR.current_field == NCUR.cycle_to_go)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	if (NCUR.current_field == NCUR.highlight_pos)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Highlight coordinate : %s",
			NCUR.highlight_pos);
	if (NCUR.current_field == NCUR.highlight_pos)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	if (NCUR.current_field == NCUR.carriage_id)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Carriage id : %s",
			NCUR.carriage_id);
	if (NCUR.current_field == NCUR.carriage_id)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	return (pos_y);
}

int				print_carriage_info(t_corewar *core,
										int pos_y, t_carriage *tmp_carr)
{
	int			r;

	wattron(NCUR.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
	NCUR.carriage_pos = tmp_carr->cur_coord;
	mvwprintw(NCUR.score_window, pos_y, 3, "Carriage with id: %d",
			tmp_carr->id);
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Position: %d",
			tmp_carr->cur_coord);
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Carry ==> [%s]",
			tmp_carr->carry ? "true" : "false");
	wmove(NCUR.score_window, ++pos_y, 3);
	r = 0;
	while (r < 15)
	{
		if (r == 0)
			wprintw(NCUR.score_window, "1 |[%. 8x]", tmp_carr->registers[r]);
		else
			wprintw(NCUR.score_window, "   %. -1x |[%. 8x]", r + 1,
					tmp_carr->registers[r]);
		r++;
		if (r % 3 == 0)
			wprintw(NCUR.score_window, "\n");
	}
	return (pos_y);
}

int				print_carriage(t_corewar *core, int pos_y, int carriage_id)
{
	t_carriage *tmp_carr;

	tmp_carr = core->carriage;
	while (tmp_carr && tmp_carr->id != (unsigned)carriage_id)
		tmp_carr = tmp_carr->next;
	if (tmp_carr)
	{
		print_carriage_info(core, pos_y, tmp_carr);
	}
	else
	{
		NCUR.carriage_pos = -1;
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_RED_BLACK));
		mvwprintw(NCUR.score_window, pos_y, 3, "Bad carriage id!");
	}
	return (pos_y);
}

int				draw_menu(t_corewar *core, int pos_y)
{
	int			carriage_id;
	int			coord;

	pos_y = draw_fields(core, pos_y);
	wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	coord = ft_atoi(NCUR.highlight_pos);
	if (coord >= 0 && ft_strlen(NCUR.highlight_pos))
		NCUR.highlight_coord = coord;
	else
		NCUR.highlight_coord = -1;
	carriage_id = ft_atoi(NCUR.carriage_id);
	pos_y += 2;
	if (carriage_id >= 0 && ft_strlen(NCUR.carriage_id))
		pos_y = print_carriage(core, pos_y, carriage_id);
	else
	{
		NCUR.carriage_pos = -1;
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_RED_BLACK));
		mvwprintw(NCUR.score_window, pos_y, 3, "Type carriage id!");
	}
	return (pos_y);
}
