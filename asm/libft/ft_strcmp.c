/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:47:47 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 14:47:51 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((!s1 && s2) || (!s2 && s1))
		return (1);
	if ((!s1 && !s2) || (!s1[0] && !s2[0]))
		return (0);
	if (!s1[0] && s2[0])
		return (-1);
	if (s1[0] && !s2[0])
		return (1);
	if ((unsigned char)s1[0] == (unsigned char)s2[0])
		return (ft_strcmp(++s1, ++s2));
	return ((unsigned char)s1[0] - (unsigned char)s2[0]);
}
