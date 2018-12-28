#include "libft.h"

void				free_char_matrix(char **str)
{
	int				counter;

	counter = 0;
	if (!str)
		return ;
	while (str[counter])
		free(str[counter++]);
	free(str);
}
