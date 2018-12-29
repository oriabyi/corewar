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
	char			*temp;

	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	else
	{
		temp = pull_out_champs_info(core);
		write(1, temp, ft_strlen(temp));
		free(temp);
	}
}

void				print_winner(t_corewar *core)
{
	char *temp;

	temp = NULL;
	if (core->champs[core->last_live].name)
		temp = ft_multjoinfr(6, "Contestant ", NULL,
							ft_itoa(core->champs[core->last_live].id), ", \"",
						core->champs[core->last_live].name, "\", has won !\n");
	ft_putstr(temp);
	free(temp);
}

int					game_over(t_corewar *core, unsigned *cycles_limit)
{
	unsigned		old_cycles;

	if (F_VISUAL)
	{
		old_cycles = core->cycles;
		core->ncur.pause = 1;
		core->cycles = (unsigned)draw(core, core->cycles, cycles_limit);
		if (core->cycles >= old_cycles)
			return (STOP_GAME);
		return (CONTINUE_GAME);
	}
	return (STOP_GAME);
}
