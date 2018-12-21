#include "../includes/corewar_header.h"

char			*pull_out_champs_info(t_corewar *core)
{
	char 		*temp;
	int 		counter;

	counter = 0;
	temp = ft_strdup("Introducing contestants...\n");
	while (counter < core->qua_bots)
	{
		temp = ft_multjoinfr(13, NULL, temp, "* Player ", NULL,
							 ft_itoa(counter + 1), ", weighing ", NULL,
							 ft_itoa(core->bots[counter].size), " bytes, \"",
							 core->bots[counter].name, "\" (\"",
							 core->bots[counter].comment, "\") !\n");
		counter++;
	}
	return (temp);
}

char			*get_field_line(t_corewar *core, size_t *i)
{
	char			temp_memory_line[LINE_SIZE];
	unsigned		j;

	j = 0;
	ft_bzero(temp_memory_line, LINE_SIZE);
	while (j == 0 || j % 63 != 0)
	{
		ft_multcat(2, temp_memory_line, (char *)core->field[(*i)].hex, " ");
		(*i)++;
		j++;
	}
	ft_strcat(temp_memory_line, (char *)core->field[(*i)++].hex);
	return (ft_strdup(temp_memory_line));
}

void 			print_memory(t_corewar *core)
{
	char			*temp;
	size_t		i;

	i = 0;
	temp = pull_out_champs_info(core);
	while (i < MEM_SIZE)
	{
		temp = ft_multjoinfr(9, NULL, temp, "0x", NULL,
				get_hex_by_int_byte((i), 4), " : ", NULL,
				get_field_line(core, &i), "\n");
	}
	write(1, temp, ft_strlen(temp));
	free(temp);
}