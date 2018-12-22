#include "libft.h"

void		ft_free_line(char **line)
{
	if (!line || !*line)
		return ;
	free(*line);
	*line = NULL;
}