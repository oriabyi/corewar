/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:39:12 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 13:39:14 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	if (!s || !f)
		return (NULL);
	if (!(p = ft_strnew(ft_strlen(s) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s + i++))
		p[i - 1] = f(i - 1, *(s + i - 1));
	return (p);
}
