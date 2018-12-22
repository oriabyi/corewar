/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:22:55 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 14:25:05 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)dest;
	i = n + 1;
	while (--i)
		*p++ = (unsigned char)c;
	return (dest);
}
