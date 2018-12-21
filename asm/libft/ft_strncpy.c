/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:51:39 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 15:51:46 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	if (count != 0)
		*dest = *src;
	if (*src && count > 1)
		ft_strncpy(dest + 1, src + 1, count - 1);
	else if (!*src && count > 0)
		while (--count + 1 > 0)
			*(dest++) = '\0';
	return (dest);
}
