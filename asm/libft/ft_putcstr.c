/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:20:39 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:20:45 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putcstr(char *str, char c)
{
	if (!str || !*str)
		return (NULL);
	if (*str == c)
		return (str);
	ft_putchar(*str);
	g_printed++;
	return (ft_putcstr(++str, c));
}
