/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:23 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 13:43:28 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*(unsigned char *)s1 == *(unsigned char *)s2)
		return (ft_memcmp(++s1, ++s2, n - 1));
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
