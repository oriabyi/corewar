/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:27:51 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:37:48 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	int				n;
	size_t			len;

	d = dst;
	s = src;
	n = (int)size;
	while (n-- && *d)
		d++;
	len = d - dst;
	n = (int)(size - len);
	if (!n)
		return (len + ft_strlen(s));
	while (*s)
	{
		if (n-- > 1)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
