#include "libft.h"
#include "get_hex_by_int_byte.c"

char 	**int_to_char_hex(size_t num, size_t len)
{
	char 		**split;
	char 		*byte;
	unsigned		i;

	i = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	byte = get_hex_by_int_byte(num, (len * 2));
	while (i < len)
	{
		split[i] = ft_strsub(byte, i * 2, 2);
		i++;
	}
	split[i] = NULL;
	free(byte);
	return (split);
}
