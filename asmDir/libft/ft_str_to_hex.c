/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:49:36 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:50:14 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_to_hex(char *c, int fd)
{
	char	*s;
	int		i;

	i = 0;
	while (c[i])
	{
		s = ft_itoa_base(c[i], 16);
		write(fd, s, ft_strlen(s));
		free(s);
		i++;
	}
	return (i);
}
