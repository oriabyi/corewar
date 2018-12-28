/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:30:14 by ariabyi           #+#    #+#             */
/*   Updated: 2017/10/30 15:30:15 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	r;

	r = 1;
	if (n < 0)
		r++;
	while (n /= 10)
		r++;
	return (r);
}

char			*ft_itoa(int n)
{
	char		*r;
	long long	ln;
	size_t		l;

	l = numlen(n);
	if (!(r = ft_strnew(l)))
		return (NULL);
	ln = (long long)n;
	if (ln < 0)
	{
		r[0] = '-';
		ln = -ln;
	}
	r[--l] = (char)(ln % 10 + '0');
	while (ln /= 10)
		r[--l] = (char)(ln % 10 + '0');
	return (r);
}
