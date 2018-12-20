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

void 			print_memory(t_corewar *core)
{
	char			*temp;
	char			temp_memory_line[LINE_SIZE];
	size_t			i = 0;
	unsigned		j = 0;

	temp = pull_out_champs_info(core);
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_bzero(temp_memory_line, LINE_SIZE);
		while (j == 0 || j % 62 != 0)
		{
			ft_multcat(2, temp_memory_line, (char *)core->field[i].hex, " ");
			i++;
			j++;
		}
		ft_strcat(temp_memory_line, (char *)core->field[i++].hex);
		i++;
		temp = ft_multjoinfr(7, NULL, temp, "0x",
							 get_hex_by_int_byte((i - 64), 4), " : ", temp_memory_line, "\n");
	}
	write(1, temp, ft_strlen(temp));
	free(temp);
}