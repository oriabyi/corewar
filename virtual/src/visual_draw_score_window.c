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

#include "../includes/corewar_header.h"

int				print_state(t_corewar *core, int pos_y)
{
	if (NCUR.pause)
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 1,
			"  _____  _______ _     _ _______ _______\n"
			"  |_____] |_____| |     | |______ |______\n"
			"  |       |     | |_____| ______| |______\n"
			"                                        ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	}
	else
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 1,
			"  _____         _______ __   __ _____ __   _  ______\n"
			"  |_____] |      |_____|   \\_/     |   | \\  | |  ____\n"
			"  |       |_____ |     |    |    __|__ |  \\_| |_____|\n"
			"                                                    ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
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
		wprintw(NCUR.score_window, "   Last live : 0\n");
		wprintw(NCUR.score_window, "   Lives in current period : 0\n");
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


	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Type cycle to go : %s",
			NCUR.cycle_to_go);
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));




	/// Carriage field
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, ++pos_y, 3, "Type carriage id : %s", core->ncur.carriage_id);
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));





	wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	/// getting carriage id from input field

	int carriage_id = ft_atoi(core->ncur.carriage_id);

	/// is valid carriage id in input field

	if (carriage_id >= 0)// && ft_strlen(core->ncur.carriage_id))
	{
		t_carriage *tmp_carr;
		/// finding carriage by id
		tmp_carr = core->carriage;
		while (tmp_carr && tmp_carr->id != carriage_id)
			tmp_carr = tmp_carr->next;

		/// whether carriage found

		if (tmp_carr)
		{
			NCUR.carriage_pos = tmp_carr->cur_coord;
			/// printing carriage id
			mvwprintw(core->ncur.score_window, pos_y + 4, 3, "Carriage with id: %d", carriage_id);
			int r = 0;
			wmove(core->ncur.score_window, pos_y + 6, 3);

			/// printing registers

			while (r < 15)
			{
				if (r == 0)
					wprintw(core->ncur.score_window, "1 |[%. 8x]", tmp_carr->registers[r]);
				else
					wprintw(core->ncur.score_window, "   %. -1x |[%. 8x]", r + 1, tmp_carr->registers[r]);

				r++;
				if (r % 3 == 0)
					wprintw(core->ncur.score_window, "\n");
			}
			wprintw(core->ncur.score_window, " Carry = %s", tmp_carr->carry ? "true" : "false");
		}
		else
		{
			NCUR.carriage_pos = -1;
			mvwprintw(core->ncur.score_window, pos_y + 58, 3, "Bad carriage id!");
		}

	}
	else
		mvwprintw(core->ncur.score_window, pos_y + 60, 3, "Type carriage id!");







	if (!NCUR.pause)
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(NCUR.score_window, 0, 0);
	wrefresh(NCUR.score_window);
}

