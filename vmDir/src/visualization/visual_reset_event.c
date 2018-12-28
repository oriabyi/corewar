/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_reset_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:30:34 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:30:40 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void			reset_game(t_corewar *core)
{
	clean_carriages(core->carriage);
	core->carriage = NULL;
	core->cycles = 0;
	core->quant_carriages = 0;
	fill_champs(core, &core->champs, core->qua_champs);
	reverse_list(&core->carriage);
	free(core->field);
	create_memory_space(core);
	fill_memory_space(core->champs, core->field, core->qua_champs);
	fill_first_positions(core->field, core->quant_carriages, core->carriage);
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
	core->qua_lives = 0;
	core->last_live = 0;
}
