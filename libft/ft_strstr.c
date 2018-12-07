/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:55:05 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:39:05 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *s3;
	char *s4;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		s3 = (char*)s1;
		s4 = (char*)s2;
		while (*s4 == *s3 && *s4)
		{
			s3++;
			s4++;
		}
		if (!*s4)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
