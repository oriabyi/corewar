/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:27:51 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/20 17:25:42 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int len;

	i = -1;
	j = 0;
	len = (long)n;
	if (n == 0)
		return (s1);
	if (len < 0)
		return (0);
	while (s1[++i] != '\0')
		;
	while (s2[j] != '\0' && n-- > 0)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
