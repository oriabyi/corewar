/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:29:41 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 15:48:21 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numows(char const *s, char c)
{
	int		i;
	int		counter;
	char	inword;

	counter = 1;
	i = -1;
	if (s == NULL)
		return (0);
	inword = (s[0] == c) ? 0 : 1;
	while (s[++i])
	{
		if (s[i] != c && inword == 1 && counter++)
			inword = 0;
		if (s[i] == c && s[i])
			inword = 1;
	}
	return (counter - 1);
}
