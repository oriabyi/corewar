/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:34:43 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 17:01:56 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char	const *s)
{
	size_t		j;
	size_t		q;
	size_t		i;
	char		*dest;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i++])
		if (i == ft_strlen(s))
			return ((!(dest = (char*)ft_memalloc(1))) ? NULL : dest);
	q = (ft_strlen(s) - 1);
	while ((s[q] == ' ' || s[q] == '\n' || s[q] == '\t') && s[q])
		q--;
	if (!(dest = (char*)malloc(q - i + 2)))
		return (NULL);
	while (s[i] && i <= q)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
