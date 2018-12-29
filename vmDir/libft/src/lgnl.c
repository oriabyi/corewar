/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:41:18 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/20 10:41:30 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					lgnl(int fd, char **line, size_t length)
{
	char			buf;
	ssize_t			len;
	int				temp_len;

	len = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	while ((temp_len = read(fd, &buf, 1) > 0) && len <= (ssize_t)length)
	{
		if (temp_len <= 0 || buf == '\0')
			break ;
		len += temp_len;
		*line = append_char(line, buf);
	}
	return ((int)ft_strlen(*line));
}
