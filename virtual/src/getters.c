#include "../includes/corewar_header.h"

char						*get_name(int fd)
{
	char					buf[PROG_NAME_LENGTH + 1];

	ft_bzero(buf, PROG_NAME_LENGTH + 1);
	read(fd, &buf, PROG_NAME_LENGTH);
	return (ft_strdup(buf));
}

unsigned char				*ft_strncpy_without_boundes
							(const unsigned char *src, size_t len, size_t max)
{
	unsigned char			*result;
	unsigned				i;

	i = 0;
	if (!(result = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1))))
		return (NULL);
	while (i < len && i < max)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}


void						get_exec_code(int fd, unsigned len,
										unsigned char **exec_code)
{
	unsigned char			buf[1024];

	read(fd, &buf, 4);
	ft_bzero(buf, 1024);
	read(fd, &buf, len);
	*exec_code = ft_strncpy_without_boundes(buf, len, 1024);
}

char						*get_comment(int fd)
{
	char					buf[COMMENT_LENGTH + 1];

	ft_bzero(buf, COMMENT_LENGTH + 1);
	read(fd, buf, COMMENT_LENGTH);
	return (ft_strdup(buf));
}

unsigned					get_size(int fd)
{
	unsigned char			buf[4];
	unsigned 				counter;
	int						power;
	ssize_t					y;

	y = 0;
	counter = 0;
	power = 7;
	read(fd, buf, 4);
	read(fd, buf, 4);
	while (counter < 4)
	{
		y += get_old_young_numbers(buf[counter++], 16, &power);
	}
	return ((unsigned)y);
}
