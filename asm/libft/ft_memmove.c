/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:19:09 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 14:19:11 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	const char	*s;
	char		*d;

	if (dest > src)
	{
		d = dest + count - 1;
		s = src + count - 1;
		while (count--)
			*(d--) = *(s--);
	}
	else
	{
		d = dest;
		s = src;
		while (count--)
			*(d++) = *(s++);
	}
	return (dest);
}
