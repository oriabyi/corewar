#include "../includes/corewar_header.h"

void 			draw_score_window(t_corewar *core, int cycle)
{
	int 		i;

	werase(core->ncur.score_window);


	if (core->ncur.pause)
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "**********Pause************");
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));

	}
	else
	{
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_GREEN_BLACK));
		mvwprintw(core->ncur.score_window, 1, 1, "**********Playing**********");
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
	while(i < core->qua_bots)
	{
		mvwprintw(core->ncur.score_window, 12 + i + (i * 6), 1, "Player%d: ", i);
		simple_print(core->ncur.score_window, i + 1);
		wprintw(core->ncur.score_window, "%s\n", core->bots[i].name);
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WWHITE_BLACK));
		wprintw(core->ncur.score_window, "   Last live : 0\n");
		wprintw(core->ncur.score_window, "   Lives in current period : 0\n");

		i++;
	}

	mvwprintw(core->ncur.score_window, i + 40, 0, "   CYCLE_TO_DIE : %d", core->cycle_to_die);
	mvwprintw(core->ncur.score_window, i + 41, 0, "   CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(core->ncur.score_window, i + 42, 0, "   NBR_LIVE : ?");
	mvwprintw(core->ncur.score_window, i + 43, 0, "   MAX_CHECKS : %d", MAX_CHECKS);

	//////////// Carriage registers print

	/// Cycles to go field
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 45, 3, "Type cycle to go : %s", core->ncur.cycle_to_go);
	if (core->ncur.current_field ==  core->ncur.cycle_to_go)
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));

	/// Bot id field
	if (core->ncur.current_field ==  core->ncur.bot_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 46, 3, "Type bot id : %s", core->ncur.bot_id);
	if (core->ncur.current_field ==  core->ncur.bot_id)
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));

	/// Carriage field
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));
	mvwprintw(core->ncur.score_window, i + 47, 3, "Type carriage id : %s", core->ncur.carriage_id);
	if (core->ncur.current_field ==  core->ncur.carriage_id)
		wattroff(core->ncur.score_window, COLOR_PAIR(CR_CL_BLACK_WHITE));



	// TODO:	Start the game

	// TODO:	Hello Oriabyi, let's play the game.
	//  		Here you can see the code, it's amazing isn't it?
	//			Your task is to fix the cycle of printing registers
	// 			goto:    /// printing registers
	//			And print your fucking carriages in the right format!
	//			ps: check by the way whether I choose the carriage from the bot

	/// getting bot id from input field

	int bot_id = ft_atoi(core->ncur.bot_id);

	if (bot_id)

		/// is valid bot

		if (bot_id <= core->qua_bots)
		{
			/// printing bot id and bot name
			mvwprintw(core->ncur.score_window, i + 49, 3, "bot %d with name: ", bot_id);
			simple_print(core->ncur.score_window, bot_id);
			wprintw(core->ncur.score_window, "%s", core->bots[bot_id - 1].name);
			wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_WHITE_BLACK));

			/// getting carriage id from input field

			int carriage_id = ft_atoi(core->ncur.carriage_id);

			/// is valid carriage id in input field

			if (carriage_id)
			{
				t_carriage *carr_to_print;
				t_carriage *tmp_carr;


				/// finding carriage by id
				tmp_carr = core->bots[bot_id].carriage;
				carr_to_print = NULL;
				while (tmp_carr)
				{
					if (tmp_carr->number == carriage_id)
						carr_to_print = core->bots[bot_id].carriage;
					tmp_carr = tmp_carr->next;
				}

				/// whether carriage found

				if (carr_to_print)
				{
					/// printing carriage id
					mvwprintw(core->ncur.score_window, i + 50, 3, "Carriage with id: %d", carriage_id);


					int r = 0;
					wmove(core->ncur.score_window, i + 52, 3);

					/// printing registers

					while (r < 16)
					{
						wprintw(core->ncur.score_window, "[%u]", carr_to_print->registers[r]);
						r++;
					}
				}
				else
					mvwprintw(core->ncur.score_window, i + 50, 3, "Bad carriage id!");

			}
			else
				mvwprintw(core->ncur.score_window, i + 50, 3, "Type carriage id!");
		}
		else
			mvwprintw(core->ncur.score_window, i + 49, 3, "Hey, we have only %d bots!", core->qua_bots);
	else
		mvwprintw(core->ncur.score_window, i + 49, 3, "Type bot id!");






	/////////////////////////////////

	if (core->ncur.pause)
		wattron(core->ncur.score_window, COLOR_PAIR(CR_CL_ORANGE_BLACK));
	box(core->ncur.score_window, 0, 0);
	wrefresh(core->ncur.score_window);
}