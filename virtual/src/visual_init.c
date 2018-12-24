#include "../includes/corewar_header.h"

int				visual_init(t_corewar *core)
{
	int 	check_code;

	core->ncur.pause = 1;
	core->ncur.pressed_button = 0;
	core->ncur.draw_speed = 100;
	core->ncur.where_pause = 0;

	fill_input_field_with_zeros(core->ncur.cycle_to_go);
	fill_input_field_with_zeros(core->ncur.champ_id);
	fill_input_field_with_zeros(core->ncur.carriage_id);
	core->ncur.current_field = core->ncur.cycle_to_go;


	check_code = create_memory_space(core);
	if (check_code)
		return (check_correctness(core, check_code));


	fill_memory_space(core->champs, core->field, core->qua_champs);
	return (0);
}