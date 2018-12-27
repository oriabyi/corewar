#include "../includes/corewar_header.h"

void 					 denote_field(t_field *field, int coord)
{
	field[coord].old_owner = field[coord].champ_id;
	if (field[coord].hex[0] == '0' && field[coord].hex[1] == '1')
		field[coord].is_alive = 1;
}

