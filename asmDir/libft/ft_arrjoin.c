/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:51:49 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:51:54 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrjoin(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = ft_arrsize(arr1);
	j = ft_arrsize(arr2);
	k = i + j;
	arr = (char **)malloc((k + 1)
			* sizeof(char *));
	arr[k] = NULL;
	while (j--)
		arr[--k] = ft_strdup(arr2[j]);
	while (i--)
		arr[--k] = ft_strdup(arr1[i]);
	return (arr);
}
