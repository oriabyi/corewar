/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dldelete_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 09:10:58 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/27 09:10:59 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dldelete_link(t_node **root, t_node *link)
{
	if (link != *root)
	{
		link->r->l = link->l;
		link->l->r = link->r;
		link->u->d = link->d;
		link->d->u = link->u;
	}
	link->h = NULL;
	link->l = NULL;
	link->r = NULL;
	link->u = NULL;
	link->d = NULL;
	link->size = 0;
	if (link->sign)
		free(link->sign);
	free(link);
}
