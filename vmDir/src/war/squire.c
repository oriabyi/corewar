/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:54:46 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:54:46 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				get_game_type(t_corewar *core)
{
	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	else
	{
		ft_putstr(pull_out_champs_info(core));
	}
}

void				print_winner(t_corewar *core)
{
	char *temp;

	temp = ft_multjoinfr(6, "Contestant ", NULL,
						ft_itoa(core->champs[core->last_live].id), ", \"",
						core->champs[core->last_live].name, "\", has won !\n");
	ft_putstr(temp);
	free(temp);
}

int					game_over(t_corewar *core, unsigned *cycles_limit)
{
	int				old_cycles;

	if (F_VISUAL)
	{
		old_cycles = core->cycles;
		NCUR.pause = 1;
		core->cycles = (unsigned)draw(core, core->cycles, cycles_limit);
		if (core->cycles >= old_cycles)
			return (STOP_GAME);
		return (CONTINUE_GAME);
	}
	return (STOP_GAME);
}
