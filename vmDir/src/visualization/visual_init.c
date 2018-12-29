/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:44:02 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:44:16 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void			fill_first_positions(t_field *field, unsigned quant_carriages,
		t_carriage *carriage)
{
	t_carriage	*head;
	unsigned	counter;

	counter = 0;
	head = carriage;
	while (counter < quant_carriages)
	{
		field[head->cur_coord].carriages_on++;
		head = head->next;
		counter++;
	}
}

int				visual_init(t_corewar *core)
{
	int			check_code;

	NCUR.pause = 1;
	NCUR.draw_speed = 100;
	NCUR.where_pause = 0;
	NCUR.highlight_coord = -1;
	NCUR.carriage_pos = -1;
	fill_input_field_with_zeros(NCUR.cycle_to_go);
	fill_input_field_with_zeros(NCUR.carriage_id);
	fill_input_field_with_zeros(NCUR.highlight_pos);
	NCUR.current_field = NCUR.cycle_to_go;
	check_code = create_memory_space(core);
	if (check_code)
		return (check_correctness(core, check_code));
	fill_memory_space(core->champs, core->field, core->qua_champs);
	fill_first_positions(core->field, core->quant_carriages, core->carriage);
	return (0);
}
