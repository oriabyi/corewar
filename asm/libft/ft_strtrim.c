/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:45:37 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 13:45:43 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!(p = ft_strdup(s)))
		return (NULL);
	i = ft_strlen(s) - 1;
	if (i == -1)
		return (p);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	free(p);
	if (!(p = ft_strsub(s, 0, i + 1)))
		return (NULL);
	return (p);
}
