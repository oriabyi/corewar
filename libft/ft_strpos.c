/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:10:01 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/02 15:10:19 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpos(const char *s, int c)
{
	size_t		place;

	place = 0;
	if (!s)
		return (0);
	while (s[place])
	{
		if (s[place] == (char)c)
			return (place);
		place++;
	}
	return (-1);
}
