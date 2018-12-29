/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_input_field_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:27:57 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:27:58 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void				fill_input_field_with_zeros(char *field)
{
	ft_bzero(field, 7);
}

int					uppend_input_field(char *field, char n)
{
	int				i;

	i = 0;
	while (i <= 5)
	{
		if (!field[i])
		{
			field[i] = n;
			field[i + 1] = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}

int					del_last_letter_input_field(char *field)
{
	int				i;

	i = 0;
	while (i <= 5)
	{
		if (field[i] &&
			!field[i + 1])
		{
			field[i] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

void				set_next_field(t_corewar *core)
{
	if (NCUR.current_field == NCUR.cycle_to_go)
		NCUR.current_field = NCUR.carriage_id;
	else if (NCUR.current_field == NCUR.highlight_pos)
		NCUR.current_field = NCUR.cycle_to_go;
	else if (NCUR.current_field == NCUR.carriage_id)
		NCUR.current_field = NCUR.highlight_pos;
}

void				set_prev_field(t_corewar *core)
{
	if (NCUR.current_field == NCUR.cycle_to_go)
		NCUR.current_field = NCUR.highlight_pos;
	else if (NCUR.current_field == NCUR.highlight_pos)
		NCUR.current_field = NCUR.carriage_id;
	else if (NCUR.current_field == NCUR.carriage_id)
		NCUR.current_field = NCUR.cycle_to_go;
}
