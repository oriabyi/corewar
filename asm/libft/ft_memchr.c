/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:38:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 13:38:28 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t length)
{
	unsigned char *p;

	p = (unsigned char *)src;
	while (--length + 1 > 0)
		if (*(p++) == (unsigned char)c)
			return (--p);
	return (NULL);
}
