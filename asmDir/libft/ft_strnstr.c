/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:57:15 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 18:28:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = -1;
	if (!*s2)
		return (char *)s1;
	while (++i != -1 && i < (signed)len && s1[i] && (j = 0) != -1)
		while (s2[j] == s1[i + j] && i + j < (signed)len && ++j)
			if (!s2[j])
				return ((char *)s1 + i);
	return (NULL);
}
