/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:46:33 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 17:46:36 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + ft_nlen(-n));
	if (n /= 10)
		return (1 + ft_nlen(n));
	return (1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_n_len(n);
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	if (n == -2147483648)
		str = ft_strdup("-2147483648\0");
	else
	{
		str[len] = '\0';
		if (n < 0 && (str[0] = '-'))
			n = -n;
		while (--len >= 0 && !str[len])
		{
			str[len] = '0' + n % 10;
			n /= 10;
		}
	}
	return (str);
}
