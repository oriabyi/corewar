#include "../includes/corewar_header.h"

char						*get_name(int fd)
{
	char					buf[PROG_NAME_LENGTH];

	read(fd, &buf, PROG_NAME_LENGTH);
	return (ft_strdup(buf));
}

unsigned char				*ft_strncpy_without_boundes(const unsigned char *src, size_t len)
{
	unsigned char			*result;
	unsigned				i;

	i = 0;
	if (!(result = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}


void						get_exec_code(int fd, unsigned len, unsigned char **exec_code)
{
	unsigned char			buf[1024];

	read(fd, &buf, 4);
	ft_bzero(buf, 1024);
	read(fd, &buf, len);
	*exec_code = ft_strncpy_without_boundes(buf, len);
}

char						*get_comment(int fd)
{
	char					buf[COMMENT_LENGTH];

	read(fd, buf, COMMENT_LENGTH);
	return (ft_strdup(buf));
}

int							get_size(int fd)
{
	char					buf[16];
	int						power;

	power = 7;
	read(fd, buf, 8);
	return (get_old_young_numbers(buf[4], 16, &power)
			+ get_old_young_numbers(buf[5], 16, &power)
			+ get_old_young_numbers(buf[6], 16, &power)
			+ get_old_young_numbers(buf[7], 16, &power));
}
