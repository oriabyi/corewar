/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:34:29 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 12:34:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static const char	*ft_find_first(const char *s, int *sn)
{
	while (ft_isspace(*s))
		s++;
	if (*s == '-' && s++)
		*sn = -1;
	else if ((*sn = 1) && (*s == '+'))
		s++;
	while (*s == '0')
		s++;
	return (s);
}

int					ft_atoi(const char *s)
{
	int		sn;
	long	nbr;

	s = ft_find_first(s, &sn);
	nbr = 0;
	while (ft_isdigit(*s))
	{
		nbr *= 10;
		nbr += *s++ - '0';
	}
	if (sn == -1)
		return ((int)-nbr);
	return ((int)nbr);
}
