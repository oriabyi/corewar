#include "../includes/corewar_header.h"

int 			draw_fields(t_corewar *core, int pos_y)
{
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(NCUR.score_window, ++pos_y, 3, "Cycle to go : %s",
			  NCUR.cycle_to_go);
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));

	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, ++pos_y, 3, "Carriage id : %s", core->ncur.carriage_id);
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	return (pos_y);
}

int 			print_carriage_info(t_corewar *core, int pos_y, t_carriage *tmp_carr)
{
	NCUR.carriage_pos = tmp_carr->cur_coord;
	mvwprintw(core->ncur.score_window, pos_y, 3, "Carriage with id: %d", tmp_carr->id);
	mvwprintw(core->ncur.score_window, ++pos_y, 3, "Position: %d", tmp_carr->cur_coord);
	mvwprintw(core->ncur.score_window, ++pos_y, 3,"Carry ==> [%s]", tmp_carr->carry ? "true" : "false");
	int r = 0;
	wmove(core->ncur.score_window, ++pos_y, 3);
	while (r < 15)
	{
		if (r == 0)
			wprintw(core->ncur.score_window, "1 |[%. 8x]", tmp_carr->registers[r]);
		else
			wprintw(core->ncur.score_window, "   %. -1x |[%. 8x]", r + 1, tmp_carr->registers[r]);

		r++;
		if (r % 3 == 0)
			wprintw(core->ncur.score_window, "\n");
	}
	return (pos_y);
}

int 			print_carriage(t_corewar *core, int pos_y, int carriage_id)
{
	t_carriage *tmp_carr;

	tmp_carr = core->carriage;
	while (tmp_carr && tmp_carr->id != carriage_id)
		tmp_carr = tmp_carr->next;
	if (tmp_carr)
	{
		print_carriage_info(core, pos_y, tmp_carr);
	}
	else
	{
		NCUR.carriage_pos = -1;
		wattron(NCUR.score_window, COLOR_PAIR(CR_CL_RED_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 3, "Bad carriage id!");
	}
	return (pos_y);
}

int 			draw_menu(t_corewar *core, int pos_y)
{

	pos_y = draw_fields(core, pos_y);
	wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	/// getting carriage id from input field

	int carriage_id = ft_atoi(core->ncur.carriage_id);

	/// is valid carriage id in input field
	pos_y += 2;
	if (carriage_id >= 0 && ft_strlen(core->ncur.carriage_id))
	{
		pos_y = print_carriage(core, pos_y, carriage_id);
	}
	else
	{
		NCUR.carriage_pos = -1;
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_RED_BLACK));
		mvwprintw(core->ncur.score_window, pos_y, 3, "Type carriage id!");
	}
	return (pos_y);
}