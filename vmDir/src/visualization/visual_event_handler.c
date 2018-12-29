/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_event_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:38:03 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 16:38:06 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

int				get_button(t_corewar *core, int cycle)
{
	int			c;

	if ((c = getch()) != -1)
		;
	else
		return (0);
	if (c == PAUSE_BUTTON && NCUR.pause)
		NCUR.pause = false;
	else if (ft_isdigit(c))
		uppend_input_field(NCUR.current_field, (char)c);
	else if (c == DELETE_BUTTON)
		del_last_letter_input_field(NCUR.current_field);
	else if ((cycle == NCUR.where_pause || c == PAUSE_BUTTON) && !NCUR.pause)
		NCUR.pause = true;
	else if (SPEED_PLUS_BUTTONS(c) && NCUR.draw_speed < MAX_SPEED)
		NCUR.draw_speed += SPEED_STEP;
	else if (SPEED_MINUS_BUTTONS(c) && NCUR.draw_speed > MIN_SPEED)
		NCUR.draw_speed -= SPEED_STEP;
	else if (c == MENU_UP_BUTTON)
		set_prev_field(core);
	else if (c == MENU_DOWN_BUTTON)
		set_next_field(core);
	else if (c == VISUAL_OFF)
		return (-1);
	return (c);
}
