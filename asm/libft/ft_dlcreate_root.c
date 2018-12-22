/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlcreate_root.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:10:47 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:10:48 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlcreate_root(t_node **root, unsigned short grid_size, int counter)
{
	(*root) = (t_node *)malloc(sizeof(t_node));
	(*root)->h = (*root);
	(*root)->r = (*root);
	(*root)->l = (*root);
	(*root)->u = NULL;
	(*root)->d = NULL;
	(*root)->size = grid_size * grid_size + counter;
	(*root)->sign = NULL;
}
