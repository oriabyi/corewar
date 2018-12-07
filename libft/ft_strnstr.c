/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:55:05 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 16:47:14 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	char	*cp;

	if (!*s2)
		return ((char*)s1);
	while (*s1 && len > 0)
	{
		i = 0;
		cp = (char*)s1;
		while (*cp++ == s2[i] && s2[i] && i < len)
			i++;
		if (!s2[i])
			return ((char*)s1);
		s1++;
		len--;
	}
	return (NULL);
}
