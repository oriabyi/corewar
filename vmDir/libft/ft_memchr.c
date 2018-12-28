/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:49:57 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:01:50 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*q;
	size_t				i;

	i = 0;
	q = (unsigned char *)s;
	while (i < n)
	{
		if (q[i] == (unsigned char)c)
			return (&q[i]);
		i++;
	}
	return (NULL);
}
