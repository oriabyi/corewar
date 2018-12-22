/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:17:29 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 18:17:31 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str)
{
	if (!str || !*str)
		return (0);
	ft_putchar(*str);
	return (1 + ft_putstr(++str));
}

int	ft_putstr_utf8(const wchar_t *str)
{
	if (!str || !*str)
		return (0);
	ft_putchar_utf8(*str);
	return (1 + ft_putstr_utf8(++str));
}
