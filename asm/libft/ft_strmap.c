/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:39:05 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 13:39:07 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*p;

	if (!s || !f)
		return (NULL);
	if (!(p = ft_strnew(ft_strlen(s) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s + i++))
		p[i - 1] = f(*(s + i - 1));
	return (p);
}
