/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:32:26 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:48:43 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(const char *str, char c, size_t n)
{
	int i;

	i = 1;
	while (*str && n)
	{
		while (*str == c && n--)
			str++;
		if (*str != c && *str)
			i++;
		while (*str != c && n--)
			str++;
		while (*str == c && n--)
			str++;
	}
	return (i);
}

static void		ft_suck(int i, int j, char **p, char **arr)
{
	arr[i] = (char *)malloc(sizeof(char) * (j + 1));
	ft_strncpy(arr[i], *p, j);
	arr[i][j] = '\0';
	*p += j;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	*p;
	char	**arr;

	if ((i = -1) && !s)
		return (NULL);
	p = (char *)s;
	arr = (char **)malloc(sizeof(char *) * ft_count(s, c, ft_strlen(s)));
	while (*p && !(j = 0) && ft_count(s, c, ft_strlen(s)) > 1)
	{
		while (*p == c)
			p++;
		if (*p != c)
		{
			while (*(p + j) && *(p + j) != c)
				j++;
			ft_suck(++i, j, &p, arr);
		}
		while (*p == c)
			p++;
	}
	arr[++i] = 0;
	return (arr);
}
