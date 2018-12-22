#include "libft.h"

static int		ft_check_range(char *s)
{
	long long	d;

	d = ft_atoll(s);
	return (d >= -2147483648 && d <= 2147483647);
}

int				ft_is_num(char *str)
{
	int j;

	j = -1;
	while (++j < (int)ft_strlen(str))
		if (!ft_isdigit(str[j]) && !((str[j] == '-'
			|| str[j] == '+') && !j))
			return (0);
	if (!ft_check_range(str))
		return (0);
	return (1);
}