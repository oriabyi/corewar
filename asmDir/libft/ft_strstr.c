/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:08:45 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 16:08:47 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = -1;
	if (!*s1 || !*s2)
		if (!*s2)
			return (char *)s1;
	while (++i != -1 && s1[i] && (j = 0) != -1)
		while (s2[j] == s1[i + j] && ++j)
			if (!s2[j])
				return ((char *)s1 + i);
	return (NULL);
}
