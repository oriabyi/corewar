#include "libft.h"
#include "get_hex_by_int_byte.c"

char 	**int_to_char_hex(size_t num)
{
	char 		**split;
	char 		*byte;
	unsigned		i;

	i = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	byte = get_hex_by_int_byte(num);
	while (i < 4)
	{
		split[i] = ft_strsub(byte, i * 2, 2);
		i++;
	}
	split[i] = NULL;
	free(byte);
	return (split);
}
