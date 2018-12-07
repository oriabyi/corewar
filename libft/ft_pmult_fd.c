/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmult_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:38:55 by ariabyi           #+#    #+#             */
/*   Updated: 2018/06/04 18:04:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_pmult_fd(int fd, int count, ...)
{
	va_list		ap;
	char		*temp;
	char		buff[4096];
	size_t		len_buff;

	ft_bzero(buff, 4096);
	va_start(ap, count);
	while (count--)
	{
		temp = va_arg(ap, char *);
		ft_strcat(buff, temp);
	}
	len_buff = ft_strlen(buff);
	write(fd, buff, len_buff);
	va_end(ap);
	return ((int)len_buff);
}
