#include "libft.h"

int	ft_arrsize(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}