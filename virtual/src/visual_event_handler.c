#include "../includes/corewar_header.h"

int 			get_button(t_corewar *core, int cycle)
{
	int 		c;

	c = getch();

	if (c != -1)
		NCUR.pressed_button = c;
	else
		return (0);

	if (c == PAUSE_BUTTON && NCUR.pause)
		NCUR.pause = false;
	else if (ft_isdigit(c))
		uppend_input_field(NCUR.current_field, (char)c);
	else if (c == DELETE_BUTTON)
		delete_last_letter_from_iput_field(NCUR.current_field);
	else if ((cycle == NCUR.where_pause  || c == PAUSE_BUTTON) && !NCUR.pause)
		NCUR.pause = true;
	else if (SPEED_PLUS_BUTTONS(c) && NCUR.draw_speed < MAX_SPEED)
		NCUR.draw_speed += SPEED_STEP;
	else if (SPEED_MINUS_BUTTONS(c) && NCUR.draw_speed > MIN_SPEED)
		NCUR.draw_speed -= SPEED_STEP;
	else if (c == MENU_DOWN_BUTTON)
		set_prev_field(core);
	else if (c == MENU_UP_BUTTON)
		set_next_field(core);
	else if (c == VISUAL_OFF)			//TODO: ??????????
	{
		F_VISUAL = FALSE;
		notification_message(core, 3, "ESCAPE!");
	}
	return (c);
}