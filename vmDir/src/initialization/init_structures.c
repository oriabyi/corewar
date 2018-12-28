/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:20:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 19:20:14 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_header.h"

t_carriage				*create_carriage(int id)
{
	t_carriage			*carriage;

	if ((carriage = (t_carriage *)malloc(sizeof(t_carriage))) == NULL)
		return (NULL);
	*carriage = (t_carriage){0, 0, 0, 0, 0, {(unsigned)(-id), 0, 0, 0, 0, 0, 0,
										0, 0, 0, 0, 0, 0, 0, 0}, 0, NULL, NULL};
	return (carriage);
}

void					init_core(t_corewar *core)
{
	core->field = NULL;
	core->champs = NULL;
	core->flags = (t_flags){0, 0};
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
	core->qua_champs = 0;
	core->qua_lives = 0;
	core->quant_carriages = 0;
	core->last_live = 0;
	core->carriage = NULL;
	core->cycles = 0;
	core->arguments = (t_args){0, 0, 0, 0};
}
