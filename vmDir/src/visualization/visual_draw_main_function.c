/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw_main_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:00:50 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 20:00:52 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

int				display_windows(t_corewar *core, int cycle)
{
	draw_memory_window(core, cycle);
	draw_score_window(core, cycle);
	return (0);
}

int				change_cycle(t_corewar *core, int cycle, unsigned *cycles_limit)
{
	if (ft_atoi(NCUR.cycle_to_go) >= 0)
	{
		F_DUMP = (unsigned)ft_atoi(NCUR.cycle_to_go);
		fill_input_field_with_zeros(NCUR.cycle_to_go);
		if (F_DUMP <= (unsigned)cycle)
		{
			reset_game(core);
			*cycles_limit = (unsigned)core->cycle_to_die;
			return (0);
		}
	}
	return (cycle + 1);
}

int				draw(t_corewar *core, int cycle, unsigned *cycles_limit)
{
	int			button;

	init_time(core);
	clock_gettime(CLOCK_MONOTONIC, &NCUR.tstart);
	while (1)
	{
		button = get_button(core, cycle);
		if (button == NEXT_CYCLE_BUTTON)
			return (cycle + 1);
		else if (button == ENTER_BUTTON
			&& NCUR.current_field == NCUR.cycle_to_go)
			return (change_cycle(core, cycle, cycles_limit));
		else if (button == EXIT)
			return (EXIT);
		display_windows(core, cycle);
		clock_gettime(CLOCK_MONOTONIC, &NCUR.tend);
		if (((double)NCUR.tend.tv_sec + 1.0e-9 * NCUR.tend.tv_nsec) -
			((double)NCUR.tstart.tv_sec + 1.0e-9 * NCUR.tstart.tv_nsec)
			> (1.0 - ((double)NCUR.draw_speed / 100)))
		{
			if (!NCUR.pause)
				break ;
		}
	}
	return (cycle + 1);
}
