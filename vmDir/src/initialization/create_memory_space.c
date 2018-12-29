/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_memory_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:19:44 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:19:46 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				fill_rank(t_field *field, int cur_qua, int qua_inrank)
{
	if (cur_qua == qua_inrank)
		return ;
	else
		fill_rank(field, (++cur_qua), qua_inrank);
	field[cur_qua].champ_id = 0;
	field[cur_qua].is_alive = 0;
	field[cur_qua].live_cycles = -1;
	field[cur_qua].carriages_on = 0;
	field[cur_qua].altered_cycles = 0;
	field[cur_qua].hex[0] = '0';
	field[cur_qua].hex[1] = '0';
	field[cur_qua].hex[2] = '\0';
}

int					create_memory_space(t_corewar *core)
{
	if (!(core->field = (t_field *)malloc(sizeof(t_field) * MEM_SIZE)))
		return (MEMORY_ERROR);
	fill_rank(core->field, 0, MEM_SIZE);
	return (0);
}
