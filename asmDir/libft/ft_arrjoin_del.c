/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:52:01 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:52:02 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrjoin_del(char **arr1, char **arr2)
{
	char **arr;

	arr = ft_arrjoin(arr1, arr2);
	ft_free_arr(arr1);
	ft_free_arr(arr2);
	return (arr);
}
