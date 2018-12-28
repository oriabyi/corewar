/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlcover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:10:19 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:11:24 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlcover(t_node **root, t_node *header)
{
	t_node *row_node;

	row_node = header->d;
	header->r->l = header->l;
	header->l->r = header->r;
	while (row_node != header)
	{
		row_node = row_node->r;
		while (row_node->h != header)
		{
			row_node->u->d = row_node->d;
			row_node->d->u = row_node->u;
			row_node->h->size--;
			row_node = row_node->r;
		}
		row_node = row_node->d;
	}
	((*root)->size)--;
}
