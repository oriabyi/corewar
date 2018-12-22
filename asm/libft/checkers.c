/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:18:08 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:18:30 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == '#' || c == ' ')
		return (1);
	return (0);
}

int		ft_is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' || c == 'z' || c == 'j' || c == 't')
		return (1);
	return (0);
}

int		ft_is_type(char c)
{
	if (ft_tolower(c) == 'x' || ft_tolower(c) == 'o' || ft_tolower(c) == 'u' ||
		ft_tolower(c) == 's' || ft_tolower(c) == 'c' || ft_tolower(c) == 'd' ||
		c == 'i' || c == 'p' || c == '%')
		return (1);
	return (0);
}

void	ft_init(t_elem **el)
{
	(*el) = (t_elem *)malloc(sizeof(t_elem));
	ft_strclr((*el)->flags);
	(*el)->width = 0;
	(*el)->precision = 0;
	(*el)->length = '\0';
	(*el)->type = '\0';
}
