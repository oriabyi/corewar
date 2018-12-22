/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:27:51 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/25 13:27:53 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		len;

	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(p = ft_strnew(len * sizeof(char) + 1)))
		return (NULL);
	if (s1)
		ft_memmove(p, s1, ft_strlen(s1) * sizeof(char));
	if (s2)
		return (ft_strcat(p, s2));
	return (p);
}
