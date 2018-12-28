/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:02:14 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 18:03:40 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t count)
{
	int l1;
	int l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((int)count - l1 - 1 > 0)
	{
		ft_memcpy(s1 + l1, s2, count - l1 - 1);
		*(s1 + count - 1) = '\0';
	}
	if (count < ft_strlen(s1))
		return (ft_strlen(s2) + count);
	return (l1 + l2);
}
