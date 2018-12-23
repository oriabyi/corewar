#include "../includes/corewar_header.h"

int					get_old_young_numbers(unsigned char num, int base, int *power)
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



unsigned					get_num_by_octet_bytes(int fd, int size)
{
	unsigned				result;
	int				power;
	unsigned char	buf;

	power = size * 2 - 1;
	result = 0;
	while (power >= 0)
	{
		read(fd, &buf, 1);
		result += get_old_young_numbers(buf, 16, &power);
	}
	return (result);
}
