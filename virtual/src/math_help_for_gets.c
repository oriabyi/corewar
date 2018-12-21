#include "../includes/corewar_header.h"

int					get_old_young_numbers(int num, int base, int *power)
{
	int				younger;
	int				older;

	if (base == 0)
		return (0);
	older = num / base;
	younger = num % base;
	older = older * raise_to_power(base, *power);
	(*power)--;
	younger = younger * raise_to_power(base, *power);
	(*power)--;
	return (older + younger);
}



int					get_num_by_octet_bytes(int fd)
{
	int				result;
	int				power;
	unsigned char	buf;

	power = 7;
	result = 0;
	while (power >= 0)
	{
		read(fd, &buf, 1);
		result += get_old_young_numbers((int)buf, 16, &power);
	}
	return (result);
}
