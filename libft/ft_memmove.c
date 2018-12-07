/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:27:35 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:31:56 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s1;
	char *s2;

	len += 1;
	s1 = (char*)src;
	s2 = (char*)dst;
	if (s1 < s2)
	{
		s1 += len - 2;
		s2 += len - 2;
		while (--len)
			*s2-- = *s1--;
	}
	else
		while (--len)
			*s2++ = *s1++;
	return (dst);
}
