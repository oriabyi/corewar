/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dluncover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:11:10 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:23:48 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dluncover(t_node **root, t_node *header)
{
	t_node *row_node;

	row_node = header->u;
	header->r->l = header;
	header->l->r = header;
	while (row_node != header)
	{
		row_node = row_node->l;
		while (row_node->h != header)
		{
			row_node->u->d = row_node;
			row_node->d->u = row_node;
			row_node->h->size++;
			row_node = row_node->l;
		}
		row_node = row_node->u;
	}
	((*root)->size)++;
}
