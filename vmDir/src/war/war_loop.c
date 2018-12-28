/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:50:24 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:50:25 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int					war_step(t_corewar *core, unsigned *cycles_limit)
{
	if (F_VISUAL == false && core->cycles && core->cycles == F_DUMP)
	{
		print_memory(core);
		return (STOP_GAME);
	}
	if (core->cycles >= F_DUMP && F_VISUAL)
	{
		core->cycles = (unsigned)draw(core, core->cycles, cycles_limit);
		if (!core->cycles)
			return (CONTINUE_GAME);
		else if ((int)core->cycles == -1)
			return (STOP_GAME);
	}
	else
		core->cycles++;
	do_process(core);
	if (core->cycles == *cycles_limit)
	{
		core->cycle_to_die = check_cycle_to_die(core);
		*cycles_limit = core->cycles + core->cycle_to_die;
	}
	if (core->cycle_to_die <= 0 || core->carriage == NULL)
		return (game_over(core, cycles_limit));
	return (CONTINUE_GAME);
}

void				war_loop(t_corewar *core)
{
	unsigned		cycles_limit;
	int				status;

	cycles_limit = (unsigned)core->cycle_to_die;
	core->cycles = 0;
	get_game_type(core);
	while (1)
	{
		status = war_step(core, &cycles_limit);
		if (status == STOP_GAME)
			break ;
	}
	if (F_VISUAL)
		visual_end(core);
	if (core->cycle_to_die <= 0 || core->carriage == NULL)
	{
		print_winner(core);
	}
}
