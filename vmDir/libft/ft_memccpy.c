/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:27:35 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:33:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	unsigned char	*temp;
	unsigned char	*sh;
	size_t			i;

	i = 0;
	temp = (unsigned char *)dst;
	sh = (unsigned char *)src;
	while (i < num)
	{
		temp[i] = sh[i];
		if (sh[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
