#include "../includes/corewar_header.h"

void 			draw_score_window(t_corewar *core, int cycle)
{
	int 		i;

	werase(core->ncur.score_window);


	if (core->ncur.pause)
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "  _____  _______ _     _ _______ _______\n"
												 "  |_____] |_____| |     | |______ |______\n"
												 "  |       |     | |_____| ______| |______\n"
												 "                                        ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));

	}
	else
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "  _____         _______ __   __ _____ __   _  ______\n"
												 "  |_____] |      |_____|   \\_/     |   | \\  | |  ____\n"
												 "  |       |_____ |     |    |    __|__ |  \\_| |_____|\n"
												 "                                                    ");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
	}

	wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	mvwprintw(core->ncur.score_window, 5, 1, "Cycles: %d", cycle);


	mvwprintw(core->ncur.score_window, 8, 1, "Speed: [");
	i = 0;
	while (i < 20)
	{
		if (i < core->ncur.draw_speed / 5)
			wprintw(core->ncur.score_window, "#");
		else
			wprintw(core->ncur.score_window, "-");
		i++;
	}
	wprintw(core->ncur.score_window, "]  %d%%", core->ncur.draw_speed);


	if (core->ncur.pressed_button > 0)
		mvwprintw(core->ncur.score_window, 10, 1, "Pressed button: \"%c\" code: %d", core->ncur.pressed_button, core->ncur.pressed_button);


	i = 0;
	while(i < core->qua_champs)
	{
		mvwprintw(core->ncur.score_window, 12 + i + (i * 6), 1, "Player %d: ", i + 1);
		simple_print(core->ncur.score_window, i + 1);
		wprintw(core->ncur.score_window, "%s\n", core->champs[i].name);
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
		wprintw(core->ncur.score_window, "   Last live : 0\n");
		wprintw(core->ncur.score_window, "   Lives in current period : 0\n");

		i++;
	}

	mvwprintw(core->ncur.score_window, i + 40, 0, "   CYCLE_TO_DIE : %d", core->cycle_to_die);
	mvwprintw(core->ncur.score_window, i + 41, 0, "   CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(core->ncur.score_window, i + 42, 0, "   MAX_CHECKS : %d", MAX_CHECKS);

	//////////// Carriage registers print

	/// Cycles to go field
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 45, 3, "Type cycle to go : %s", core->ncur.cycle_to_go);
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));

	/// Bot id field
	if (core->ncur.current_field ==  core->ncur.champ_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 46, 3, "Type champ id : %s", core->ncur.champ_id);
	if (core->ncur.current_field ==  core->ncur.champ_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));

	/// Carriage field
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 47, 3, "Type carriage id : %s", core->ncur.carriage_id);
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));



	/// getting champ id from input field

	int champ_id = ft_atoi(core->ncur.champ_id);

	if (champ_id)

		/// is valid champ

		if (champ_id <= core->qua_champs)
		{
			/// printing champ id and champ name
			mvwprintw(core->ncur.score_window, i + 49, 3, "champ %d with name: ", champ_id);
			simple_print(core->ncur.score_window, champ_id);
			wprintw(core->ncur.score_window, "%s", core->champs[champ_id - 1].name);
			wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
			/// getting carriage id from input field

			int carriage_id = ft_atoi(core->ncur.carriage_id);

			/// is valid carriage id in input field

			if (carriage_id >= 0)
			{
				t_carriage *tmp_carr;

				/// finding carriage by id
				tmp_carr = core->champs[champ_id - 1].carriage;
				while (tmp_carr && tmp_carr->id != carriage_id)
					tmp_carr = tmp_carr->next;

				/// whether carriage found

				if (tmp_carr)
				{
					/// printing carriage id
					mvwprintw(core->ncur.score_window, i + 50, 3, "Carriage with id: %d", carriage_id);


					int r = 0;
					wmove(core->ncur.score_window, i + 52, 3);

					/// printing registers

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
				}
				else
				{
					mvwprintw(core->ncur.score_window, i + 50, 3, "Bad carriage id!");
				}

			}
			else
				mvwprintw(core->ncur.score_window, i + 50, 3, "Type carriage id!");
		}
		else
			mvwprintw(core->ncur.score_window, i + 49, 3, "Hey, we have only %d champs! ", core->qua_champs);
	else
		mvwprintw(core->ncur.score_window, i + 49, 3, "Type champ id!");





	/////////////////////////////////

	if (!core->ncur.pause)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
	else
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(core->ncur.score_window, 0, 0);
	wrefresh(core->ncur.score_window);
}