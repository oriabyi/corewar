/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:48:23 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 15:51:04 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	if ((!s1[0] && !s2[0]) || count == 0)
		return (0);
	if ((unsigned char)s1[0] == (unsigned char)s2[0])
		return (ft_strncmp(++s1, ++s2, count - 1));
	return ((unsigned char)s1[0] - (unsigned char)s2[0]);
}
