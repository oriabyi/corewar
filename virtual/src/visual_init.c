#include "../includes/corewar_header.h"

int				visual_init(t_corewar *core)
{
	int 	check_code;

	NCUR.pause = 1;
	NCUR.pressed_button = 0;
	NCUR.draw_speed = 100;
	NCUR.where_pause = 0;

	fill_input_field_with_zeros(NCUR.cycle_to_go);
	fill_input_field_with_zeros(NCUR.champ_id);
	fill_input_field_with_zeros(NCUR.carriage_id);
	NCUR.current_field = NCUR.cycle_to_go;


	check_code = create_memory_space(core);
	if (check_code)
		return (check_correctness(core, check_code));


	fill_memory_space(core->champs, core->field, core->qua_champs);
	return (0);
}