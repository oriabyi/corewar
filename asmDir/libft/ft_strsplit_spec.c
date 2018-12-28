/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:48:09 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:48:11 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_suck(int i, int j, char **p, char **arr)
{
	arr[i] = (char *)malloc(sizeof(char) * (j + 1));
	ft_strncpy(arr[i], *p, j);
	arr[i][j] = '\0';
	*p += j;
}

char			**ft_realloc(char **arr, int length)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char*) * (length + 1));
	i = -1;
	while (++i < length)
		new[i] = arr[i];
	new[i] = NULL;
	free(arr);
	return (new);
}

char			**ft_strsplit_spec(char const *s, char *c, char end)
{
	int		i;
	int		j;
	char	*p;
	char	**arr;

	if ((i = -1) && !s)
		return (NULL);
	p = (char *)s;
	arr = (char **)malloc(sizeof(char *));
	while (*p && *p != end && !(j = 0))
	{
		while (*p && ft_strchr(c, *p))
			p++;
		if (*p && !ft_strchr(c, *p) && *p != end)
		{
			while (*(p + j) && *(p + j) != end && !ft_strchr(c, *(p + j)))
				j++;
			arr = ft_realloc(arr, ++i + 1);
			ft_suck(i, j, &p, arr);
		}
		while (*p && ft_strchr(c, *p))
			p++;
	}
	arr[++i] = 0;
	return (arr);
}
