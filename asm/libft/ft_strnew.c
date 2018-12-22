/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:41:55 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 13:41:57 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	if (!(p = (char *)ft_memalloc(size + 1)))
		return (NULL);
	ft_memset(p, '\0', size + 1);
	return (p);
}
