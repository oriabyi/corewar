/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:58:35 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:58:37 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

char						*get_name(int fd)
{
	char					buf[PROG_NAME_LENGTH + 1];

	ft_bzero(buf, PROG_NAME_LENGTH + 1);
	read(fd, &buf, PROG_NAME_LENGTH);
	return (ft_strdup(buf));
}

int							get_exec_code(int fd, unsigned len,
										unsigned char **exec_code)
{
	unsigned char			buf[1024];
	ssize_t					read_length;

	ft_bzero(buf, 1024);
	read_length = read(fd, &buf, len);
	*exec_code = ft_strncpy_without_boundes(buf, len, 1024);
	return (read_length == len);
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
	unsigned				counter;
	int						power;
	ssize_t					y;

	y = 0;
	counter = 0;
	power = 7;
	read(fd, buf, 4);
	while (counter < 4)
	{
		y += get_old_young_bits(buf[counter++], 16, &power);
	}
	return ((unsigned)y);
}
