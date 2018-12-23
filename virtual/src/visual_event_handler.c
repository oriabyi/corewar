#include "../includes/corewar_header.h"

int 			get_button(t_corewar *core, int cycle)
{
	int 		c;

	c = getch();

	if (c != -1)
		core->ncur.pressed_button = c;
	else
		return (0);

	if (c == PAUSE_BUTTON && core->ncur.pause)
		core->ncur.pause = false;
	else if (ft_isdigit(c))
		uppend_input_field(core->ncur.current_field, (char)c);
	else if (c == DELETE_BUTTON)
		delete_last_letter_from_iput_field(core->ncur.current_field);
	else if ((cycle == core->ncur.where_pause  || c == PAUSE_BUTTON) && !core->ncur.pause)
		core->ncur.pause = true;
	else if (SPEED_PLUS_BUTTONS(c) && core->ncur.draw_speed < MAX_SPEED)
		core->ncur.draw_speed += SPEED_STEP;
	else if (SPEED_MINUS_BUTTONS(c) && core->ncur.draw_speed > MIN_SPEED)
		core->ncur.draw_speed -= SPEED_STEP;
	else if (c == MENU_DOWN_BUTTON)
		set_prev_field(core);
	else if (c == MENU_UP_BUTTON)
		set_next_field(core);
	else if (c == VISUAL_OFF)			//TODO: ??????????
	{
		F_VISUAL = FALSE;
		exit_message(core, 3, "ESCAPE!");
	}
	return (c);
}